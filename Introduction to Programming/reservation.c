#include <stdio.h>
int main (void)

{
	int x[10];
	int i;
	int a;
	int counter = 0;
	int id = 0;
	int flag;
	int input;

	for (i = 0; i < 10; i++)
	{
		x[i] = 0;
// creates an array of all rooms and initializes all with 0
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
		if (a == 0)
		{
			flag = 0;
			for (i = 0; i < 10; i++)
			{
// checks through array for an empty room
				if (x[i] == 0)
				{
					x[i] = id;
					counter ++;
					printf ("\nYour room has been reserved!\n");
					printf ("Your I.D: is %d\n", id);
					flag = 1;
					i = 10;
				}
			}
			if (flag == 0)
			{
					printf ("\nI'm sorry, but the hotel is full\n");
			}	
		}
		else if (a == 1)
		{
// takes User ID input
			flag = 0;
			printf ("\nPlease enter your I.D. number\n");
			scanf ("%d", &input);
			for (i = 0; i < 10; i++)
			{
// checks the array to see if ID is there
				if (input == x[i])
				{
					x[i] = 0;
					counter --;
					printf ("You have successfully cancelled your reservation\n");
					flag = 1;
					i = 10;
				}
			}
			if (flag == 0)
			{
					printf ("I'm sorry, but you do not have a reserved room\n");
			}
		}
		else if (a == 2)
		{
			flag = 0;
			for (i = 0; i < 10; i++)
			{
// checks to see if anybody is in the hotel
				if (x[i] != 0)
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
					printf ("I.D. %d\n",x[i]);
				}
			}
			else
			{
					printf ("The hotel is empty\n");
			}
		}
		else
		{
			return (0);
		}
	}
}

