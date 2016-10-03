#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSONGS 5000

char* week[] = {"sundayShuffle.txt", "mondayShuffle.txt ", "tuesdayShuffle.txt", "wednesdayShuffle.txt", "thursdayShuffle.txt", "fridayShuffle.txt", "saturdayShuffle.txt"};
int dayNum;

void shuffle ();
void create ();
void days();
int main (int argc, char* argv[])
{
	FILE *infp;
	char *playlist[MAXSONGS];
	int numSongs = 0;
	int i;	

	if ((infp = fopen(argv[1],"r")) == NULL)
	{
		printf ("cannot open the file playlist.txt\n");
		return;
	}

// Allocates dynamic memory for the 2d array
	for (i = 0; i < MAXSONGS; i++)
	{
		playlist[i] = ((char*) malloc (50 * sizeof(char)));
		if (playlist[i] == NULL)
		{
			printf ("cannot allocate memory");
		}
	}
// Points to song in dynamic memory
	while (fgets(playlist[numSongs], 50, infp) != NULL)
	{
		numSongs++;
	}

	fclose (infp);
	
	shuffle (playlist, numSongs);

	days(argc, argv);	
	create (playlist, numSongs, dayNum);

	return (0);
}

void shuffle (char *playlist[], int numSongs)
{
	clock_t start_t, end_t,total_t;
	int i, j;
	char* temp;
	start_t = clock();
	srand(time(0));
	for (i = 0; i < numSongs; i++)
	{
		j = (rand() % numSongs);
		temp = playlist[i];
		playlist[i] = playlist[j];
		playlist[j] = temp;
	}
	end_t = clock();
	total_t = (double)((end_t - start_t)/CLOCKS_PER_SEC);
	printf ("Total time taken by CPU: %.15f\n", total_t); 
	return;
}

void create (char *playlist[], int numSongs, int dayNum)
{
	int i;
	FILE *outfp;
	if ((outfp = fopen(week[dayNum],"w")) == NULL)
	{
		printf ("cannot open the file %s\n, week[dayNum]");
		return;
	}
	for (i = 0; i < numSongs; i++)
	{
		fputs(playlist[i],outfp);
	}
	fclose(outfp);
	return;
}

void days (int argc, char*argv[])
{
	if (argc != 3)
	{
		printf ("Only insert one day");
	}
	if (strcmp (argv[2], "sunday") == 0)
	{
		dayNum = 0;
	}
	else if (strcmp (argv[2], "monday") == 0)
	{
		dayNum = 1;
	}
	else if (strcmp (argv[2], "tuesday") == 0)
	{
		dayNum = 2;
	}
	else if (strcmp (argv[2], "wednesday") == 0)
	{
		dayNum = 3;
	}
	else if (strcmp (argv[2], "thursday") == 0)
	{
		dayNum = 4;
	}
	else if (strcmp (argv[2], "friday") == 0)
	{
		dayNum = 5;
	}
	else if (strcmp (argv[2], "saturday") == 0)
	{
		dayNum = 6;
	}
	else
	{
		printf ("Sorry you mispelled the day\n");
	}
	return;
}























