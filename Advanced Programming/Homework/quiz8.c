// Thomas Nguyen
// Student ID: W1061089

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} NODE;


NODE *search (NODE *head, int data)
{
	NODE *previous = NULL;
	NODE *current = head;
	while (current != NULL && data >= current -> data)
	{
		previous = current;
		current = current -> next;
	}
	return previous;
}

NODE *insert (NODE *head, int newval)
{
	NODE *temp;
	if ((temp = (NODE*)malloc (sizeof(NODE))) == (NODE*)NULL)
	{
		printf ("memory could not be allocated \n");
		return 0;
	}
	(temp -> data) = newval;
	temp -> next = NULL;
	NODE *previous;
	previous = search (head,newval);
	if (head == NULL)
	{
		head = temp;
		return head;
	}
	else if (previous == NULL)
	{
		temp -> next = head;
		head = temp;
	}
	else
	{
		temp -> next = previous -> next;
		previous -> next = temp;
	}
	return head;
}

void clear (NODE **head)
{
	NODE *current = *head;
	NODE *next;
	while (current != NULL)
	{
		next = current -> next;
		free (current);
		current = next;
	}
	*head = NULL;	
}

void traverse (NODE *head)
{
	NODE *pnode = head;
	while (pnode != NULL)
	{
		printf ("%d ", pnode -> data);
		pnode = pnode -> next;
	}
	printf("\n");
}

int main (void)
{
	NODE *head = NULL;
	int i;
	int x;
	clear (&head);
	for (i = 0; i < 5; i++)
	{
		printf ("What number would you like to insert: ");
		scanf ("%d", &x);
		head = insert (head,x);
		traverse (head);
	}
	return 0;
}






