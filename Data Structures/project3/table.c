// Thomas Nguyen W1061089
// MWF 10:30  T 2:15

/*
 *	This code table.c is abstract and manipulates the data from the text
 *	files to produce certain results for unique.c, bincount.c, and parity.c
 *	clients. It utilizes the concept of hashing to more efficiently 
 *	find, add and remove elements from the array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "set.h"
#define EMPTY 0
#define FILLED 1
#define DELETED 2 

/*
 *	This structure keeps track of the length of the array, the number
 *	of elements in the array, the array of elements, and the corresponding
 *	array of flags
*/
struct set {
	int count;
	int length;
	char **elts;
	char *flags;
};

// A function that is commonly used to hash for strings
unsigned hashString (char *s)
{
	unsigned hash = 0;
	while (*s != '\0')
		hash = 31 * hash + *s ++;
	return hash;
}


// This function creates a set for the elements and a set for the flags
// Best Run Time: O(n)	Worst Run Time: O(n)
SET *createSet (int maxElts)
{
	SET *sp;
	int i;
	sp = malloc(sizeof(SET));
	assert (sp != NULL);
	sp -> count = 0;
	sp -> length = maxElts;
	sp -> elts = malloc (sizeof (char*) * maxElts);
	assert (sp -> elts != NULL);
	sp -> flags = malloc (sizeof(char) * maxElts);
	assert (sp -> flags != NULL);
	for (i=0; i < maxElts; i++)
	{
		sp -> flags[i] = EMPTY;
	}
	return sp;
}

// This function frees the dynamically allocated elements, then the flags and 
// structure as a whole
// Best Run Time: O(n)	Worst Run Time: O(n)
void destroySet (SET *sp)
{
	int i;
	assert (sp != NULL);
	for (i = 0; i < sp -> length; i++)
	{
		if (sp -> flags[i] == FILLED)
		{
			free (sp -> elts[i]);
		}
	}
	free (sp -> flags);
	free (sp);
}

// This returns the number of elements in the array
// Best Run Time: O(1)	Worst Run Time: O(1)
int numElements (SET *sp)
{
	assert (sp != NULL);
	return (sp->count);
}

// Searches through the elements array and utilizes the flag array to check whether
// the element is there are not. Uses a pointer and bools to indicate whether the
// element is there, and returns the index of where the element should go or should be.
// Best Run Time: O(1) Worst Run Time: O(n)
int findElement (SET *sp, char *elt, bool *found)
{
	int i;
	int del = -1;
	int start = hashString (elt) % sp -> length;
	for (i = 0; i < sp -> length; i++, start++, start = start % sp->length)
	{
		if (sp -> flags[start] == DELETED)
		{
			if (del == -1)
				del = start;	
		}
		else if(sp -> flags[start] == FILLED)
		{
			if (strcmp(elt, sp -> elts[start]) == 0)
			{
				*found = true;
				return (start);
			}
		}		
		else if (sp -> flags[start] == EMPTY)
		{
			if (del != -1)
			{
				*found = false;
				return (del);
			}
			return (start);	
		}
	}	
	return (del);
}

// Uses the function findElement to tell user if the element is there or not
// Best Run Time: O(1)	Worst Run Time: O(n)
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

// Uses the bool pointer and index provided from findElement to determine whether
// the element needs to be added to the set. If so, the flag is changed to FILLED as well
// Best Run Time: O(1)	Worst Run Time: O(n)
bool addElement (SET *sp, char *elt)
{
	int s, i;
	bool found;
	assert (sp != NULL && elt != NULL);
	if (sp->count == sp->length)
		return (false);
	s = findElement (sp, elt, &found);
	if (found == true)
		return (false);
	sp -> elts[s] = strdup (elt);
	sp -> count++;
	sp -> flags[s] = FILLED;
	return (true);
}

// Uses the bool pointer and index provided from findElement to determine whether
// the element needs to be removed from the set. If so, the flag is changed to DELETED as well
// Best Run Time: O(1)	Worst Run Time: O(n)
bool removeElement (SET *sp, char *elt)
{
	int s, i;
	bool found;
	assert (sp != NULL && elt != NULL);
	s = findElement (sp, elt, &found);
	if (found == false)
		return (false);
	free (sp-> elts[s]);
	sp -> count --;
	sp -> flags[s] = DELETED;
	return (true);
}
