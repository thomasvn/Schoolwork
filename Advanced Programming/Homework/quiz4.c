#include <stdio.h>
#include <string.h>

	typedef struct {
		char firstName[50];
		char lastName[50];
		int active;
	}AUTHOR;

	typedef struct {
		char title[50];
		double ISBN;
		double rating;
		char subject[50];
		AUTHOR *author;
	}BOOKS;

int main (void)
{
	
	AUTHOR infoA[5] =
	{
		{"Gloria","Anzaldua",23},
		{"Ryan", "Holiday", 8},
		{"Wayne", "Booth", 12},
		{"Gerald","Graft", 15},
		{"William","Golding", 21}
	};
	
	BOOKS infoB[5] = 
	{
		{"Borderlands, La Frontera", 9781879960749,3.8,"Society", &infoA[0]},
		{"The Obstacle Is the Way", 9781591846352,4.2,"Growth",&infoA[1]},
		{"The Craft of Research", 9780226065663, 3,"Tutorial",&infoA[2]},
		{"They Say / I Say", 9780393912753, 3.6,"Tutorial",&infoA[3]},
		{"Lord of the Flies", 9780140772869, 4.3,"Survival",&infoA[4]}
	};

	show_Info(&infoB[0]);
}

void show_Info (BOOKS *infoB)
{
	int i;
	AUTHOR *infoA;
	infoA = infoB -> author;

	for (i = 0; i < 5; i++)
	{
		printf ("Title: %s \n", infoB -> title);
		printf ("Author: %s %s \n", infoA -> firstName, infoA -> lastName);
		printf ("Years Active: %d \n", infoA -> active);
		printf ("ISBN: %.0lf \n", infoB -> ISBN);
		printf ("Rating: %.1lf \n", infoB -> rating);
		printf ("Subject: %s \n \n", infoB -> subject);
		infoA++;
		infoB++;
	}
}	

