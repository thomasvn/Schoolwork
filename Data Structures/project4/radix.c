/*	Thomas Nguyen W1061089
 *	Wednesday, 2:15 - 5:00
 *
 *	In this code, I create the main for the ADT functions created
 *	in deque.c. By utilitzing the ADT functions, this code sorts
 *	a list of numbers that are inputted by the user using Radix
 *	Sorting and deques.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "deque.h"
#define r 10

int main (void)
{
	int i,j,k,x,y,z;
	int num;
	int max = 0;
/*
 * 	Create the main deque which acts like a buffer
*/
	DEQUE *md;
		md = createDeque();
	DEQUE *dp[r];

/*
 *	Creating 'r' amount of bins to Radix sort
*/	
	for (i = 0; i < r; i++)
	{
		dp[i] = createDeque();
	}

/*
 * 	Loops and saves into the main deque until the user enters an
 * 	invalid input. Also keeps track of the max number in the deque
 *	for later use.
*/
	while (1)
	{
		printf("Enter a number. Press anything else to sort:\n");
		if (scanf("%d", &num) == 1)
		{
			if (num < 0)
			{
				printf ("Invalid Input\n");
				break;
			}
			addLast (md, num);
			if (num > max)
				max = num;
		}
		else
			break;
	}
	
/*
 * 	Function used to solve the amount of significant digits we
 * 	need to check in radix sorting
*/
	x = ceil((log(max + 1))/(log(r)));


/*
 *	One loop used to check each significant digit. The other loops
 *	are used to move the numbers from main deque into their bins and
 *	then back into main deque.
*/
	for(i = 0; i < x; i++)
	{
		while(numItems(md) != 0)
		{
			z = removeFirst(md);
			y = (z / ((int)pow(10,i))) % 10;
			addLast(dp[y], z);
		}
		for (j = 0; j < r; j++)
		{
			while (numItems(dp[j]) != 0)
			{
				z = removeFirst(dp[j]);
				addLast(md,z);
			}
		}
	}
	
/*
 *	Prints out the sorted numbers  after the completion of
 *	Radix sorting.
*/
	printf ("\nSorted Numbers:\n");
	for (i = 0; i < numItems(md); i++)
	{
		k = removeFirst(md);
		printf ("%d\n", k);
		addLast(md,k);	
	}

/*
 *	Frees everything in the main deque and the bins
*/
	for (i = 0; i < r; i++)
	{
		destroyDeque(dp[i]);
	}
	destroyDeque(md);
}
