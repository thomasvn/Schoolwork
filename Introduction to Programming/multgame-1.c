#include <time.h>
#include <stdlib.h>
#include <stdio.h>
int main (void)

{
	int x;
	int i;
	int number1;
	int number2;
	int counter = 0;
	int percent;

	srand ((int) time (NULL));

	for(i = 0; i < 10; i++)
	{
		number1 = rand () % 13;
		number2 = rand () % 13;
		printf("\nMultiply %d ", number1);
		printf("by %d \n", number2);
		scanf("%d", &x);
		if (x == number1 * number2)
		{
			printf("Nice Job!\n");
			counter++;
		}
		else if (i < 9)
		printf("Try again\n");
	}
	printf("You got %d out of 10 correct\n",counter);
	percent = counter * 10;
	printf("You got %d%% in the game!\n",percent);
}

