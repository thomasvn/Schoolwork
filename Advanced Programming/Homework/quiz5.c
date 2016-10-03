#include <stdio.h>

int main (void)
{
	int rows, cols;
	int value;
	printf ("Which row is it in? \n");
	scanf ("%d", &rows);
	printf ("\nWhich Column is it in? \n");
	scanf ("%d", &cols);
	if (cols>rows)
	{
		printf ("\nThe number of columns cannot exceed the number of rows \n");
		return;
	}
	else
	{
		printf ("\nThe value is: %d \n", pascal(rows-1, cols-1));
		return;
	}
}

int pascal (int r, int c)
{
	if (c == 0 || r==c)
	{
		return 1;
	}
	else
	{
		return ((pascal(r-1,c-1))+(pascal(r-1,c)));
	}
}


