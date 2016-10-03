// Main program file MAIN5.C
// Written by Daniel W. Lewis
// Revised Jan 2, 2015
//
// Purpose: Create double size and half size versions of an image.

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/stat.h>
#include "bmp3.h"

IMAGE	*HalfSize(IMAGE *image) ;
IMAGE	*DoubleSize(IMAGE *image) ;

typedef struct
	{
	char	*format ;
	IMAGE	*(*function)() ;
	double	param ;
	} OPTION ;

OPTION	*GetOption(int argc, char **argv, OPTION options[]) ;
void	DisplayImage(char *filespec, char *format, ...) ;

int main(int argc, char **argv)
	{
	char *src_filespec, *dst_filespec ;
	static OPTION options[] =
		{
		{"Half Size",			HalfSize,			  0.0},
		{"Double Size",			DoubleSize,			  0.0},
		{NULL,					NULL,				  0.0}
		} ;
	OPTION *option ;
	IMAGE *image ;

	if (argc != 3 && argc != 4)
		{
		fprintf(stderr, "Usage: %s src-file dst-file {option#}\n", argv[0]) ;
		exit(255) ;
		}

	src_filespec = argv[1] ;
	dst_filespec = argv[2] ;

	image = ReadBMP24(src_filespec) ;

	if ((option = GetOption(argc, argv, options))== NULL)
		{
		fprintf(stderr, "Usage: %s src-file dst-file {option#}\n", argv[0]) ;
		exit(255) ;
		}

	image = (option->function)(image, option->param) ;

	WriteBMP24(dst_filespec, image) ;
	FreeImage(image) ;
	DisplayImage(dst_filespec, option->format, option->param) ;

	return 0 ;
	}

IMAGE *DoubleSize(IMAGE *src)
	{
	int i,j;
	int rows,cols;
	IMAGE *dest = NewImage (src -> rows*2, src -> cols*2);
	for (i = 0;i < (dest -> rows); i+=2)
	{
		for (j = 0; j < (dest -> cols); j+=2)
		{
			dest -> pxlrow[i][j] = src -> pxlrow[i/2][j/2];
			dest -> pxlrow[i+1][j] = src -> pxlrow[i/2][j/2];
			dest -> pxlrow[i+1][j+1] = src -> pxlrow[i/2][j/2];
			dest -> pxlrow[i][j+1] = src -> pxlrow[i/2][j/2];
		}
	}
	return (dest);
	}

IMAGE *HalfSize(IMAGE *src)
	{
	int i,j;
	int x,y,z;
	int rows, cols;
	IMAGE *dest = NewImage ((src -> rows+1)/2, (src -> cols+1)/2);
	for (i = 0; i < (src -> rows); i+=2)
	{
		for (j = 0; j < (src -> cols); j+=2)
		{
			if ((i+1) == (src -> rows))
			{
				if ((j+1) == (src -> cols))
				{
					x = (src -> pxlrow[i][j].blu);
					y = (src -> pxlrow[i][j].grn);
					z = (src -> pxlrow[i][j].red);
				}
				else
				{
					x = (src -> pxlrow[i][j].blu + src -> pxlrow[i][j+1].blu)/2;
					y = (src -> pxlrow[i][j].grn + src -> pxlrow[i][j+1].grn)/2;
					z = (src -> pxlrow[i][j].red + src -> pxlrow[i][j+1].red)/2;
				}
			}
			else
			{
				if ((j+1) == (dest -> cols))
				{
					x = (src -> pxlrow[i][j].blu + src -> pxlrow[i+1][j].blu)/2;
					y = (src -> pxlrow[i][j].grn + src -> pxlrow[i+1][j].grn)/2;
					z = (src -> pxlrow[i][j].red + src -> pxlrow[i+1][j].red)/2;
				}
				else
				{
					x = (src -> pxlrow[i][j].blu + src -> pxlrow[i][j+1].blu + src -> pxlrow[i+1][j].blu + src -> pxlrow[i+1][j+1].blu)/4;
					y = (src -> pxlrow[i][j].grn + src -> pxlrow[i][j+1].grn + src -> pxlrow[i+1][j].grn + src -> pxlrow[i+1][j+1].grn)/4;
					z = (src -> pxlrow[i][j].red + src -> pxlrow[i][j+1].red + src -> pxlrow[i+1][j].red + src -> pxlrow[i+1][j+1].red)/4;
				}
			}
			dest -> pxlrow[i/2][j/2].blu = x;
			dest -> pxlrow[i/2][j/2].grn = y;
			dest -> pxlrow[i/2][j/2].red = z;
		}
	}
	return (dest);
	}

OPTION *GetOption(int argc, char **argv, OPTION options[])
	{
	unsigned number, index = 0 ;

	// count number of options
	for (number = 0; options[number].function != NULL; number++) ;

	if (argc == 4)
		{
		sscanf(argv[3], "%u", &index) ;
		}
	else
		{
		printf("\nOptions:\n\n") ;
		for (index = 0; index < number; index++)
			{
			char title[100] ;
			sprintf(title, options[index].format, options[index].param) ;
			printf("%2d: %s\n", index + 1, title) ;
			}

		printf("\nOption? ") ;
		scanf("%u", &index) ;
		}

	return (1 <= index && index <= number) ? &options[index - 1] : NULL ;
	}

void DisplayImage(char *filespec, char *format, ...)
	{
	char progspec[200], command[1000], *program_files, title[100] ;
	struct stat filestat ;
	va_list args ;
	
	va_start(args, format) ;
	vsprintf(title, format, args) ;
	va_end(args) ;

#if defined(_WIN32)
	program_files = getenv("ProgramFiles(x86)") ;
	if (program_files == NULL) program_files = getenv("C:\\Program Files") ;
	if (program_files == NULL) program_files = "" ;

	sprintf(progspec, "%s\\IrfanView\\i_view32.exe", program_files) ;
	if (stat(progspec, &filestat) == 0 && (filestat.st_mode & S_IFREG) != 0)
		{
		sprintf(command, "\"%s\" %s /hide=7 /title=%s", progspec, filespec, title) ;
		}
	else sprintf(command, "mspaint \"%s\"\n", filespec) ;
#elif defined(__unix)
	sprintf(command, "qiv \"%s\"", filespec) ;
#elif defined(__APPLE__)
	sprintf(command, "open \"%s\"", filespec) ;
#endif 
	system(command) ;
	}

