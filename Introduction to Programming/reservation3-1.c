#include <stdio.h>
#include <string.h>

	int i;
	int a;
	int counter = 0;
	char hotel[10][20];
	void reserve (void);
	void cancel (void);
	void list (void);

int main (void)
{
	int i;
	int a;
	int counter = 0;
	char hotel[10][20];

	for (i = 0; i < 10; i++)
	{
		hotel[i][0] = '\0';
// creates a multidimensional array and assigns each a null character
	}
	printf ("\nWelcome to the Hotel Reservation Program!\n");
	printf ("Press '0' to reserve a room\n");
	printf ("Press '1' to cancel a reservation\n"); 
	printf ("Press '2' to show all reservations\n"); 
	printf ("Press any other number to quit the program\n");
	while (1)
	{
		scanf ("%d", &a);
// checks for the user's choice of action
		switch (a)
		{
			case(0):
			{
				reserve();
				break;
			}
			case(1):
			{
				cancel();
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
reserve (void)
{
	int i;
	int j;
	char name[20];
				for (i = 0; i < 10; i++)
				{
// checks through array for an empty room
					if (hotel[i][0] == '\0')
					{
						printf ("\nPlease enter your first name\n");
						scanf ("%s", name);
						for (j = 0; j < 10; j++)
						{
							if(strcmp(name, hotel[j]) == 0)
							{
								printf ("That name is already taken, try again\n");
								i = 10;
								break;
							}
							else if (j == 9)
							{
								strcpy (hotel[i], name);
								counter ++;
								printf ("\nYour room has been reserved!\n");
								printf ("Thank you for choosing our hotel, %s\n",hotel[i]);
								i = 10;
								break;
							}
						}
					}		
					else if (i == 9)
					{
						printf ("\nI'm sorry, but the hotel is full\n");
					}
				}
}

void 
cancel (void)
{
	
	int i;
	char input[20];
				printf ("\nPlease enter your first name to cancel your reservation\n");
				scanf ("%s", input);
				for (i = 0; i < 10; i++)
				{
// checks the array to see if name is there
					if (strcmp(input, hotel[i]) == 0)
					{
						hotel[i][0] = '\0';	
						counter --;
						printf ("You have successfully cancelled your reservation\n");
						printf ("Hope to see you again soon, %s \n", input);
						break;
					}
					if (i == 10)
					{	
						printf ("I'm sorry, but you do not have a reserved room\n");
					}
				}
}
	
void 
list (void)
{
	int i;
	int flag = 0;
				for (i = 0; i < 10; i++)
				{
// checks to see if anybody is in the hotel
					if (hotel[i][0] != '\0')
					{
						flag = 1;
					}
				}
				if (flag == 1)
				{
//prints array if there are people with reserved rooms
					for (i = 0; i < 10; i++)
					{
						printf ("\nRoom %d\n", i);
						printf ("Name: %s\n", hotel[i]);
					}
				}
				if (flag == 0)
				{
					printf ("The hotel is empty\n");
				}
}

