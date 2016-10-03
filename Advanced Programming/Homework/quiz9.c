//Thomas Nguyen
//Student ID: W1061089

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}NODE;


NODE* delete (NODE *current, int k)
{
	int i;
	for (i = 1; i < k; i++)
	{
		current = current -> next;
	}
	current -> next = (current -> next -> next);
	current = current -> next;
	return (current);
}

NODE* initialize (NODE *head, int n)
{
	NODE *newNode;
	NODE *temp;
	int i;
	for (i = 0; i < n; i++)
	{
		if ((newNode = (NODE*)malloc (sizeof(NODE))) == (NODE*)NULL)
		{
			printf ("memory could not be allocated \n");
			return 0;
		}
		if (head == NULL)
		{
			newNode -> data = (i+1);
			head = newNode;
			temp = newNode;
			continue;
		}
		else
		{
			temp -> next = newNode;
			newNode -> data = (i+1);
			temp = newNode;
		}
	}
	newNode -> next = head;	
	return (head);
}

void traverse (NODE* current)
{
	NODE* temp = current;
	printf ("Prisoners alive: %d", current -> data);
	current = current -> next;
	while (current -> data != temp -> data)
	{
		printf ("%d", current -> data);
		current = current -> next;
	}
	printf ("\n");
}

int main (void)
{
	NODE* head = NULL;
	int n, k, i;
	printf("How many citizens would you like to insert: ");
	scanf ("%d", &n);
	printf ("How many people would you like to skip at a time: ");
	scanf ("%d" , &k);
	NODE * current  = initialize (head, n);
	for (i = 0; i < (n-1); i++)
	{
		current = delete(current, k);
		traverse(current);
	}
	return (0);
}
