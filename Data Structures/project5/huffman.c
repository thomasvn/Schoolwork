/*
 *	Thomas Nguyen
 *	Wednesday 2:15 - 5:00 PM
 *	
 *	This code huffman.c, uses two arrays, a binary heap 
 *	and functions from tree.c. By using these, huffman.c
 *	reads from a file and compresses the file by changing
 *	the amount of bits each character or octal is assigned.
 *	The amount of bits each item is assigned is determined
 *	by the amount of times it shows up when the file is read - 
 *	the more times it occurs, the fewer bits we want to assign it.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "tree.h"
#include "pack.h"

// Returns the locations of the parent, left child, and right child
#define p(x) (((x)-1)/2)
#define l(x) (((x)*2)+1)
#define r(x) (((x)*2)+2)

int count [257];
struct tree *heap[257];
struct tree *leaves[257];
int heapCount = 0;

/*
 *	Inserts the tree into the correct position after searching
 *	and swapping the heap.
 *	Run Time: O(h)
*/
void insert (struct tree *np)
{
	int idx;
	idx = heapCount++;
	while ((idx) > 0 && (getData(np) < getData(heap[p(idx)])))
	{
		heap[idx] = heap[p(idx)];
		idx = p(idx);
	}
	heap[idx] = np;
}

/*
 *	Iteratively reheaps and compares to find the tree
 *	with the smallest ocurrence value then deletes and 
 * 	returns it.
 *	Run Time: O(h)
*/
struct tree *delete (void)
{
	int child;
	int idx = 0;
	struct tree *min;
	struct tree *tp;
	min = heap[0];
	tp = heap[--heapCount];
	while(l(idx) < heapCount)
	{
		child = l(idx);
		if (r(idx) < heapCount && getData(heap[l(idx)]) > getData(heap[r(idx)]))
			child = r(idx);
		if (getData(tp) > getData(heap[child]))
		{
			heap[idx] = heap[child];
			idx = child;
		}
		else
			break;
	}
	heap[idx] = tp;
	return (min);
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

// Initialize all arrays (O(h))
	for (i = 0; i < 257; i++)
	{
		count[i] = 0;
		heap[i] = NULL;
		leaves[i] = NULL;
	}	

// Make sure there is the correct amount of inputs (O(1))
	if (argc != 3)
	{
		printf("You have inputted the incorrect number of files \n");
		return 0;		
	}

// Open file and read from file (O(n))
	fp = fopen(argv[1], "r");
	assert (fp != NULL);	
	while ((c = fgetc(fp)) != EOF)
	{
		count[c]++;
	}
	fclose(fp);

// Store non-zero data into array and insert into heap (O(h))
	for (i = 0; i < 257; i++)
	{
		if (count[i] != 0)
		{
			leaves[i] = createTree(count[i], NULL, NULL);
			insert (leaves[i]);	
		}
	}

// CreateTree for EOF and insert into heap (O(1))
	leaves[256] = createTree(0, NULL, NULL);
	insert (leaves[256]);

// Create the huffman tree by deleting the two smallest then
// combining the data to create a new tree (O(1))
	while (heapCount > 1)
	{
		l = delete();
		r = delete();
		j = (getData(l)) + (getData(r));
		insert (createTree (j, l, r));
	}
	
// Goes through the entire leaves arrays and checks to see
// if it was printable, then calls printCode to print the bits (O(h))
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

