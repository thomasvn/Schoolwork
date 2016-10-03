#include <stdio.h>
#include <string.h>

int counter = 0;
char hotel[10][20];
void reserve (char *name);
void cancel (char *name);
void list (void);

int main (void)
{
	char *p;
	int a;
	char name[20];
	for (p = hotel[0]; p <= hotel[9]; p+=20)
	{
		*p = '\0';
		// creates a multidimensional array and assigns each a null character
	}
	while (1)
	{
		printf ("\nWelcome to the Hotel Reservation Program!\n");
		printf ("Please enter your name below!\n");
		scanf ("%s", name);
		printf ("Press '0' to reserve a room\n");
		printf ("Press '1' to cancel a reservation\n"); 
		printf ("Press '2' to show all reservations\n"); 
		printf ("Press any other number to quit the program\n");
		scanf ("%d", &a);
		// checks for the user's choice of action
		switch (a)
		{
			case(0):
				{
					reserve(name);
					break;
				}
			case(1):
				{
					cancel (name);
					break;
				}
			case(2):
				{
					list();
					break;
				}
			default:
				return(0);
		}
	}
}

	void
reserve (char *name)
{
	char *str;
	char *p;
	int i;
	int n;
	for (str = hotel[0]; str <= hotel[9]; str += 20)
	{
		if(strcmp(name, str) == 0)
		{
			printf ("That name is already taken, try again\n");
			return;
		}
	}
	for (p = hotel[0]; p <= hotel[9]; p += 20)
		if (*p == '\0')
		{
			printf ("How many rooms would you like to reserve? We will try to reserve as many as we can for you\n");
			scanf ("%d",&n);
			for (i = 0;i < n  &&  p <= hotel[9];p += 20)
			{
				if (*p == '\0')
				{
					strcpy (p, name);
					i++;		
					counter ++;
				}
			}
			printf ("\n %d room(s) have been reserved!\n", i);
			printf ("Thank you for choosing our hotel, %s\n", name);
			break;
		}		
		else if (p == hotel[9])
		{
			printf ("\nI'm sorry, but the hotel is full\n");
		}
}

	void 
cancel (char *name)
{
	char *p;
	int flag = 0;
	for (p = hotel[0];p <= hotel[9]; p += 20)
	{
		// checks the array to see if name is there
		if (strcmp(name, p) == 0)
		{
			*p = '\0';	
			counter --;
			flag = 1;
		}
		if (p == hotel[9])
		{
			if (flag == 0)
				printf ("I'm sorry, but you do not have a reserved room\n");
		}
	}
	printf ("You have successfully cancelled your reservation(s)\n");
	printf ("Hope to see you again soon, %s \n", name);
}

	void 
list (void)
{
	int i;
	char *p;
	int flag = 0;
	for (p = hotel[0]; p <= hotel[9]; p += 20)
	{
		// checks to see if anybody is in the hotel
		if (*p != '\0')
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		//prints array if there are people with reserved rooms
		i = 1;
		for (p = hotel[0]; p <= hotel[9]; p += 20)
		{
			printf ("\nRoom %d\n", i);
			printf ("Name: %s\n", p);
			i++;
		}
	}
	if (flag == 0)
	{
		printf ("The hotel is empty\n");
	}
}

