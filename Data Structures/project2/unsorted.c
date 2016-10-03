// Thomas Nguyen W1061089
// MWF 10:30  T 2:15
/*
 *	This code unsorted.c is abstract and manipulates the data from
 *	the text files to produce certain results for the unique.c,
 *	bincount.c, and parity.c codes.
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

// Finds the element's position in the array. If not found it returns -1
// Run Time: O(n)
int findElement (SET *sp, char *elt)
{
	int i;
	for (i = 0; i < sp -> count; i++)
	{
		if (strcmp (elt, sp -> elts[i]) == 0)
			return(i);
	}
	return (-1);
}

// Uses the function findElement
// Run Time: O(n)
bool hasElement (SET *sp, char *elt)
{
	assert (sp!= NULL && elt != NULL);
	if (findElement (sp, elt) != -1)
	{
		return (true);
	}
	else
	return (false);	
}

// Adds an element to the end of the array
// Run Time: O(n)
bool addElement (SET *sp, char *elt)
{
	assert (sp != NULL && elt != NULL && sp->count != sp -> length);
	if (hasElement(sp, elt) == true)
		return (false);
	sp -> elts[sp->count] = strdup (elt);
	sp -> count++;
	return (true);
}

// Finds the element asked to remove and removes it. Then replaces that blank spot with the last element.
// Run Time: O(n)
bool removeElement (SET *sp, char *elt)
{
	int i;
	assert (sp != NULL && elt != NULL);
	i = findElement (sp, elt);
	if (i == -1)
		return (false);
	free (sp -> elts[i]);
	sp -> elts[i] = sp -> elts[sp -> count -1];
	sp -> elts[sp -> count - 1] = NULL;
	sp -> count--;
	return (true);
}


