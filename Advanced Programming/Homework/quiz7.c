#include <stdio.h>
#include <math.h>

int main (void)
{
	int number;
	FILE *infp;
	if ((infp = fopen ("data.txt", "r")) == NULL)
		printf ("cannot open the file data.txt\n");
	number = countp (infp);
	fclose (infp);
	printf ("There are %d numbers that are greater than 100\n", number);
	return (0);
}

int countp (FILE *infp)
{
	int ret;
	int counter = 0;
	int number;
	while ((ret = fscanf(infp, "%d", &number)) != EOF)
	{
		if (number > 100)
			counter++;
	}
	return (counter);
}
