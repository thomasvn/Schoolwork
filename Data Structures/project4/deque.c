/*	Thomas Nguyen  W1061089
 *	Wednesday, 2:15 - 5:00
 *	
 *	In this code deque.c, abstract functions are created for a 
 *	main and are utilized to create a maze and solve a maze in
 *	maze.c. I utilized a circular and doubly linked list to
 *	manipulate the deque.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deque.h"

/*	Declaration of two structures. One for the node and one
 *	for the head of the linked list.
 *	Run Time: O(1)
*/
typedef struct node {
	int data;
	struct node  *next;
	struct node  *prev;
}NODE;

struct deque {
	int count;
	NODE *head;
};

/*	This dynamically allocates memory for the deque pointer 
 * 	and node pointers of the circular linked list. It sets
 *	the circular linked list up using a dummy node.
 *	Run Time: O(1)
*/
DEQUE *createDeque(void)
{
	NODE *np;
	DEQUE *dp;
	dp = malloc (sizeof (DEQUE));
	np = malloc (sizeof (NODE));
	assert (dp != NULL && np != NULL);
	dp -> head = np;
	np -> next = np;
	np -> prev = np;
	dp -> count = 0;
	return (dp);
}

/*	Frees the entire deque by moving forward and freeing
 *	the nodes previous.
 *	Run Time: O(n)
*/
void destroyDeque (DEQUE *dp)
{
	NODE *np;
	np = dp -> head -> next -> next;
	while (np != dp -> head)
	{
		free (np -> prev);
		np = np -> next;
	}
	if (np -> prev != np)
		free (np -> prev);
	free (np);
	return;
}

/* 	Simply returns the number of items in the deque for 
 *	the client
 *	Run Time: O(1)
*/
int numItems (DEQUE *dp)
{
	return (dp -> count);
}

/*	Allocates memory for a node and inserts it into the 
 *	beginning of the deque by rearranging pointers.
 *	Run Time: O(1)
 */
void addFirst (DEQUE *dp, int x)
{
	NODE *np;
	np = malloc (sizeof (NODE));
	assert  (np != NULL);
	np -> data = x;
	np -> next = dp -> head -> next;	
	np -> prev = np -> next -> prev;
	np -> next -> prev = np;
	dp -> head -> next = np;
	dp -> count++;
}

/*	Allocates memory for a node and inserts it into the
 *	end of the deque by rearranging pointers.
 *	Run Time: O(1)
*/
void addLast (DEQUE *dp, int x)
{
	NODE *np;
	np = malloc (sizeof (NODE));
	assert (np != NULL);
	np -> data = x;
	np -> next = dp -> head;
	np -> prev = dp -> head -> prev;
	np -> prev -> next = np;
	dp -> head -> prev = np;
	dp -> count++;
}

/*	Frees the first node after the dummy node and
 *	rearranges pointer to maintain the deque
 *	Run Time: O(1)
*/
int removeFirst (DEQUE *dp)
{
	int x;
	assert (dp != NULL && dp -> count != 0);
	dp -> head -> next = dp -> head -> next -> next;
	x = dp -> head -> next -> prev -> data;
	free (dp -> head -> next -> prev);
	dp -> head -> next -> prev = dp -> head;
	dp -> count--;
	return (x);
}

/*	Frees the last node in the deque and rearranges
 *	the pointers to maintain the deque
 *	Run Time: O(1)
*/
int removeLast (DEQUE *dp)
{
	int x;
	assert (dp != NULL && dp -> count != 0);
	dp -> head -> prev = dp -> head -> prev -> prev;
	x = dp -> head -> prev -> next -> data;
	free (dp -> head -> prev -> next);
	dp -> head -> prev -> next = dp -> head;	
	dp -> count--;
	return (x);
}

/*	Returns the first item of the deque
 *	Run Time: O(1)
*/
int getFirst (DEQUE *dp)
{
	return (dp -> head -> next -> data);
}


/*	Returns the last item of the deque
 *	Run Time: O(1)
*/
int getLast (DEQUE *dp)
{
	return (dp -> head -> prev -> data);
}




