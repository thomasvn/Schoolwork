// Main program file MAIN9.C
// Written by:
// Daniel W. Lewis (dlewis@scu.edu)
// Computer Engineering Department
// Santa Clara University
// Revised Jan 2, 2015
//
// Purpose: Create and manipulate a linked list of audio segments

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "wav.h"

typedef struct LIST_TAG
	{
	struct LIST_TAG	*nextnode ;
	AUDIO			*segment ;
	} LIST ;

LIST *	CreateList(AUDIO *segment1, AUDIO *segment2, AUDIO *segment3) ;
AUDIO *	CombineSegments(LIST *list) ;

void DisplayAudio(char *filespec) ;

int main(int argc, char **argv)
	{
	AUDIO *src, *dst, *part1, *part2, *part3 ;
	char *src_filespec, *dst_filespec ;
	unsigned one_third ;
	LIST *list ;

	if (argc != 3)
		{
		fprintf(stderr, "Usage: %s src-file dst-file\n", argv[0]) ;
		exit(255) ;
		}

	src_filespec = argv[1] ;
	dst_filespec = argv[2] ;

	src = ReadWAV16(src_filespec) ;
	one_third = src->num_samples / 3 ;

	part1 = CopySegment(src, 0, one_third) ;
	part2 = CopySegment(src, one_third + 1, 2*one_third) ;
	part3 = CopySegment(src, 2*one_third+1, src->num_samples - 1) ;

	list  = CreateList(part1, part2, part3) ;
	dst   = CombineSegments(list) ;

	WriteWAV16(dst_filespec, dst) ;
	DisplayAudio(dst_filespec) ;

	return 0 ;
	}

LIST *CreateList(AUDIO *segment1, AUDIO *segment2, AUDIO *segment3)
	{
		LIST* audio1;
		LIST* audio2;
		LIST* audio3;
		LIST* head = NULL;
		if ((audio1 = (LIST*) malloc(sizeof(LIST))) == (LIST*) NULL)
		{
			printf ("Memory could not be allocated \n");
			return 0;
		}	
		if ((audio2 = (LIST*) malloc(sizeof(LIST))) == (LIST*) NULL)
		{
			printf ("Memory could not be allocated \n");
			return 0;
		}	
		if ((audio3 = (LIST*) malloc(sizeof(LIST))) == (LIST*) NULL)
		{
			printf ("Memory could not be allocated \n");
			return 0;
		}
		audio1 -> segment = segment1;
		audio2 -> segment = segment2;
		audio3 -> segment = segment3;
		audio1 -> nextnode = audio2;
		audio2 -> nextnode = audio3;
		audio3 -> nextnode = NULL;
		return (audio1);
	}	

AUDIO *CombineSegments(LIST *list)
	{
		AUDIO *end;
		end = NewAudio (0, list -> segment -> sample_rate);
		while (list != NULL)
		{
			end = InsertSegment (end, list -> segment, end -> num_samples);
			list = list -> nextnode;	  
		}
		return (end);
	}

void DisplayAudio(char *filespec)
	{
	char progspec[200], command[1000], *program_files ;
	struct stat filestat ;

#if defined(_WIN32)
	program_files = getenv("ProgramFiles(x86)") ;
	if (program_files == NULL) program_files = getenv("C:\\Program Files") ;
	if (program_files == NULL) return ;

	sprintf(progspec, "%s\\Audacity\\audacity.exe", program_files) ;
	if (stat(progspec, &filestat) != 0) return ;
	if ((filestat.st_mode & S_IFREG) == 0) return ;

	sprintf(command, "\"%s\" %s", progspec, filespec) ;
#elif defined(__unix)
	sprintf(command, "audacity \"%s\"", filespec) ;
#elif defined(__APPLE__)
	sprintf(command, "/Applications/Audacity/Audacity.app/Contents/MacOS/Audacity \"%s\"", filespec) ; 
#endif 
	system(command) ;
	}
