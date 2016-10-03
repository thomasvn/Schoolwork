/*	Thomas Nguyen  W1061089
 *	Wednesday, 2:15 - 5:00
 *	
 *	This code, deque.cpp, is an Abstract Data Type whose
 *	clients are radix.cpp and maze.cpp - one which sorts
 *	numbers and one which creates a maze that solves itself.
 *	This code uses the deque.h class Deque.
*/

#include <cassert>
#include "deque.h"

/*
 *	This a constructor member function which is similar
 *	to the createDeque function. It allocates memobry
 *	for the first node and then points it to itself.
 *	Run Time: O(1)
*/
Deque :: Deque()
{
	head = new NODE;
	head -> next = head;
	head -> prev = head;
	count = 0;
}

/*
 *	Deletes the entire deque by moving forward and freeing
 *	the nodes previous.
 *	Run Time: O(n)
*/
Deque :: ~Deque()
{
	NODE *np;
	np = head -> next -> next;
	while (np != head)
	{
		delete (np -> prev);
		np = np -> next;
	}
	if (np -> prev != np)
		delete (np -> prev);
	delete (np);
	return;
}

/*
 * 	Simply returns the number of items in the deque for 
 *	the client
 *	Run Time: O(1)
*/
int Deque :: size()
{
	return (count);
}

/*
 *	Allocates memory for a node and inserts it into the 
 *	beginning of the deque by rearranging pointers.
 *	Run Time: O(1)
 */
void Deque :: addFirst (int x)
{
	NODE *np = new NODE;
	assert  (np != NULL);
	np -> data = x;
	np -> next = head -> next;	
	np -> prev = np -> next -> prev;
	np -> next -> prev = np;
	head -> next = np;
	count++;
}

/*
 *	Allocates memory for a node and inserts it into the
 *	end of the deque by rearranging pointers.
 *	Run Time: O(1)
*/
void Deque :: addLast (int x)
{
	NODE *np = new NODE;
	assert (np != NULL);
	np -> data = x;
	np -> next = head;
	np -> prev = head -> prev;
	np -> prev -> next = np;
	head -> prev = np;
	count++;
}

/*
 *	Frees the first node after the dummy node and
 *	rearranges pointer to maintain the deque
 *	Run Time: O(1)
*/
int Deque :: removeFirst ()
{
	int x;
	assert (head != NULL && count != 0);
	head -> next = head -> next -> next;
	x = head -> next -> prev -> data;
	delete (head -> next -> prev);
	head -> next -> prev = head;
	count--;
	return (x);
}

/*
 *	Frees the last node in the deque and rearranges
 *	the pointers to maintain the deque
 *	Run Time: O(1)
*/
int Deque :: removeLast ()
{
	int x;
	assert (head != NULL && count != 0);
	head -> prev = head -> prev -> prev;
	x = head -> prev -> next -> data;
	delete (head -> prev -> next);
	head -> prev -> next = head;	
	count--;
	return (x);
}
/*
 *	Returns the first item of the deque
 *	Run Time: O(1)
*/
int Deque :: getFirst ()
{
	return (head -> next -> data);
}

/*
 *	Returns the last item of the deque
 *	Run Time: O(1)
*/
int Deque :: getLast ()
{
	return (head -> prev -> data);
}




