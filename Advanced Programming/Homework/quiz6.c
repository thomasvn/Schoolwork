//Thomas Nguyen
//W1061089

#include <stdio.h>
#include <string.h>
#include <pthread.h>
char string[50];
int mid;

void *upper ()
{
	int i;
	for (i = 0; i < mid; i++)
	{
		string[i] = toupper(string[i]);
	}
	return (NULL);
}

void *lower ()
{
	int i, length;
	length = strlen(string);
	if ((length % 2) == 1)
	{
		mid++;
	}
	for (i = mid; i < length; i++)
	{
		string[i] = tolower(string[i]);
	}
	return (NULL);
}

int main (void)
{
	pthread_t first;
	pthread_t last;
	printf ("Enter a sentence here\n");
	scanf ("%[^\n]s\n", string);
	int mid = ((strlen(string))/2);
	pthread_create (&first, NULL, upper, NULL);
	pthread_create (&last, NULL, lower, NULL);
	pthread_join (first, NULL);
	pthread_join (last, NULL);
	printf ("Your final result is:");
	printf ("%s\n",string);
	return(0);
}	
