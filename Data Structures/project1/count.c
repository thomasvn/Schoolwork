// Thomas Nguyen W1061089
// Tuesday 2:15 - 5:00

// This project takes in a file in the certain /scratch/coen12 location and counts the number of words in the file

#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 30

// This function opens a file, and counts the number of words in the file using fscanf
void wordCount(char *fileName)
{
	FILE *infp;
	char temp[MAX_WORD_LENGTH+1];
	int count = 0;

// While opening file, it also checks to see if the file could be opened	
	if ((infp = fopen(fileName, "r")) == NULL)
	{
		printf("Could not open the file\n");
		return;
	}

	while (fscanf(infp,"%s",temp) != EOF)
	{
		count ++;
	}

	fclose(infp);
	printf ("%d total words\n", count);
	return;
}

// Uses command line arguments to see if user has inputted correct amount of arguments 
// then calls the wordCount function and passes command line argument
int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("You have not entered the correct number of arguments\n");
		return 0;
	}
	wordCount(argv[1]);
	return 0;
}

