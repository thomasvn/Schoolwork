#include <stdio.h>

int main (void)
{
	int array [5][5];
	int i,j;
	int x;
	int number = 1;
	for (i = 0; i<5; i++)
	{
		for (j = 0; j<5; j++)
		{
			array[i][j] = number;
			number++;
		}
	}
	x = sum (5, 5, array);
	printf ("%d \n", x);
}

int sum (int nRows, int nColumns, int array[nRows][nColumns])
{
	int i,j;
	int sum = 0;
	for (i = 0; i < nRows; i++)
	{
		for (j = 0; j<nColumns; j++)
		{
			sum += array[i][j];
		}
	}
	return (sum);
}

		

