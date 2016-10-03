#include <stdio.h>
#include <string.h>

int main (void)
{
	int i;
	char array [5][20];
	for (i = 0; i < 5; i++)
	{
		printf ("Please Enter a Name\n");
		scanf ("%s \n", array [i]);
	}
	largest_size(5,20,array);
}

int largest_size (int nRows, int nColumns, char array[nRows,nColumns])
{
	int count = 0;
	int high = 0;
	char *j;
	while (*p != '\0')
	{
		count++;
		if (count > high)
		{
			high = count;
			j = p;
		}
	}


