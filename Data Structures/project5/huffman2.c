/*
 *	Thomas Nguyen
 *	Wednesday 2:15 - 5:00 PM
 *	
 *	This code huffman.c, uses three arrays to read from a file
 *	and compress it by changing the amount of bits for the
 *	letters that occur more frequently in the file. By using
 *	the functions from tree.c, it is able to create a huffman
 *	tree from the read file to reorganize the number of bits
 *	for each item in the file.
 *
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "tree.h"
#include "pack.h"

#define p(x) (((x)-1)/2)
#define l(x) (((x)*2)+1)
#define r(x) (((x)*2)+2)

int count [257];
struct tree *heap[257];
struct tree *leaves[257];
int heapCount = 0;

/*
 *	Inserts the tree into the end of the heap and then increments
 *	the heapCount.
 *	Run Time: O(1)
*/
void insert (struct tree *np)
{
	heap[heapCount++] = np;
}

/*
 *	Deletes the tree that has the smallest occurence value
 *	and replaces it with the tree at the end.
 *	Run Time: O(n)
*/
struct tree *delete (void)
{
	int min = 0;
	int i;
	struct tree *tp;
	for (i = 0; i < heapCount; i++)
	{
		if ((getData(heap[i])) < getData(heap[min]))
		{
			min = i;
		}
	}
	tp = heap[min];
	heap[min] = heap[heapCount -1];
	heapCount--;
	return (tp);
}

/*
 *	Recursively calls itself to see if the parent is NULL
 *	or not. Once it reaches base case, it will pop the stack
 *	and print 0 if it is on the left and 1 if it is on the right
 *	Run Time: O(h)
*/
void printCode(struct tree *np)
{
	if (getParent(np) == NULL)
		return;
	printCode (getParent(np));
	if (np == getLeft(getParent(np)))
		printf ("0");
	else
		printf ("1"); 
}


int main (int argc, char *argv[])
{
	FILE *fp;
	int c,i,j;
	struct tree *l;
	struct tree *r;

// Initialize all arrays
	for (i = 0; i < 257; i++)
	{
		count[i] = 0;
		heap[i] = NULL;
		leaves[i] = NULL;
	}	

// Make sure there is the correct amount of inputs
	if (argc != 3)
	{
		printf("You have inputted the incorrect number of files \n");
		return 0;		
	}

// Open file and read from file
	fp = fopen(argv[1], "r");
	assert (fp != NULL);	
	while ((c = fgetc(fp)) != EOF)
	{
		count[c]++;
	}
	fclose(fp);

// Store non-zero data into array and insert into heap
	for (i = 0; i < 257; i++)
	{
		if (count[i] != 0)
		{
			leaves[i] = createTree(count[i], NULL, NULL);
			insert (leaves[i]);	
		}
	}

// CreateTree for EOF and insert into heap
	leaves[256] = createTree(0, NULL, NULL);
	insert (leaves[256]);

// Create the huffman tree by deleting the two smallest then
// combining the data to create a new tree
	while (heapCount > 1)
	{
		l = delete();
		r = delete();
		j = (getData(l)) + (getData(r));
		insert (createTree (j, l, r));
	}
	
// Goes through the entire leaves arrays and checks to see
// if it was printable, then calls printCode to print the bits	
	for (i = 0; i < 257; i++)
	{
		if (leaves[i] != 0)
		{
			if (isprint(i))
			{
				printf ("'%c': ", i);
				printf ("%d ", count[i]);
				printCode(leaves[i]);
				printf ("\n");
			}
			else
			{
				printf ("%o: ", i);
				printf ("%d ", count[i]);
				printCode(leaves[i]);
				printf ("\n");
			}
		}
	}

// Does the file compression given the Huffman Tree
	pack (argv[1],argv[2],leaves);

}

