#include <stdio.h>

int main (void)
{
	int i,j;
	int array [5][5];
	int count = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			array[i][j] = 0;
		}
	}
	for (i = 0; i < 5; i++)
	{
		array[i][count] = 1;
		array[i][4-count] = 1;
		count++;
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf ("%d", array[i][j]);
		}
			printf ("\n");
	}
}
		
