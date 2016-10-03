// Thomas Nguyen W1061089
// MWF 10:30  T 2:15
/*
 *	This code sorted.c is abstract and manipulates the data from
 *	the text files to produce certain results for the unique.c,
 *	bincount.c, and parity.c codes. It is different from 
 *	unsorted.c in the idea that the sets will now be sorted and
 *	binary search will be implemented
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "set.h"

/*
 *	This structure keeps track of the length of the array, the number
 *	of elements in the array, and the array of elements
*/
struct set {
	int count;
	int length;
	char **elts;
};

// This function creates a set for the elements to go inside
// Run Time: O(1)
SET *createSet (int maxElts)
{
	SET *sp;
	sp = malloc(sizeof(SET));
	sp -> count = 0;
	sp -> length = maxElts;
	sp -> elts = malloc (sizeof (char*) *maxElts);
	assert (sp -> elts != NULL);
	return sp;
}

// This function frees the dynamically allocated elements then the structure as a whole
// Run Time: O(n)
void destroySet (SET *sp)
{
	int i;
	assert (sp != NULL);
	for (i = 0; i < sp -> count -1; i++)
	{
		free (sp -> elts[i]);
	}
	free (sp);
}

// This returns the number of elements in the array
// Run Time: O(1)
int numElements (SET *sp)
{
	return (sp->count);
}

// Uses Binary Search to look for the correct element and return its position. Also changes
// pointer found to signify whether the element was found or not
// Run Time: O(logn)
int findElement (SET *sp, char *elt, bool *found)
{
	int lo, mid, hi, diff;
	lo = 0;
	hi = (sp -> count-1);
	while (lo <= hi)
	{
		mid = ((lo+hi)/2);
		diff = strcmp (elt, sp->elts[mid]);
		if (diff < 0)
			hi = mid - 1;
		else if (diff > 0)
			lo = mid + 1;
		else
		{
			*found = true;
			return (mid);
		}
	}
	*found = false;
	return lo;
}

// Uses the function findElement
// Run Time: O(logn)
bool hasElement (SET *sp, char *elt)
{
	bool found;
	assert (sp!= NULL && elt != NULL);
	findElement (sp, elt, &found);
	if (found == true) 
	{
		return (true);
	}
	return (false);
}

// Uses findElement to shift everything after the correct position one to the right
// and adds in the element in the correct position
// Run Time: O(n)
bool addElement (SET *sp, char *elt)
{
	int s, i;
	bool found;
	assert (sp != NULL && elt != NULL && sp->count != sp->length);
	s = findElement (sp, elt, &found);
	if (found == true)
		return (false);
	for (i = sp->count; i > s; i--)
	{
		sp -> elts[i] = sp -> elts[i-1];
	}
	sp -> elts[s] = strdup (elt);
	sp -> count++;
	return (true);
}

// Uses findElement to shift everything starting from the right position one to the left
// and overwriting the element in the correct position
// Run Time: O(n)
bool removeElement (SET *sp, char *elt)
{
	int s, i;
	bool found;
	assert (sp != NULL && elt != NULL);
	s = findElement (sp, elt, &found);
	if (found == false)
		return (false);
	free (sp-> elts[s]);
	for (i = s; i < sp->count; i++)
	{
		sp -> elts[i] = sp -> elts[i+1];
	}
	sp -> count --;
	return (true);
}
