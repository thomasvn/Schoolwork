// Main program file MAIN4.C
// Written by Daniel W. Lewis
// Revised Jan 2, 2015
//
// Purpose: Change the brightness and contrast of an image.

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "bmp2.h"

IMAGE		*AdjustBrightness(IMAGE *image, double percent) ;
IMAGE		*AdjustContrast(IMAGE *image, double percent) ;

typedef struct
	{
	char	*format ;
	IMAGE	*(*function)() ;
	double	param ;
	} OPTION ;

OPTION		*GetOption(int argc, char **argv, OPTION options[]) ;
void		DisplayImage(char *filespec, char *format, ...) ;

int main(int argc, char **argv)
	{
	char *src_filespec, *dst_filespec ;
	static OPTION options[] =
		{
		{"Brightness (%.1f)",	AdjustBrightness,	  120},
		{"Contrast (%.1f)",		AdjustContrast,		  150},
		{NULL,					NULL,				    0}
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

IMAGE *AdjustBrightness(IMAGE *image, double percent)
	{
	int i, j;
	unsigned red, grn, blu;
	unsigned Rows = GetRows (image);
	unsigned Cols = GetCols (image);
	double value = (((percent-100)/100)*255);
	for (i = 0; i < Rows; i++)
	{
		for (j = 0; j < Cols; j++)
		{
			GetRGB (image, i, j, &red, &grn, &blu);
//After receiving the RGB from each pixel, we change the brightness of each by multiplying by a percentage of its original vaue, After we check if it surpasses the upper threshold
			red += value;
			if (red > 255)
			{
				red = 255;
			}
			grn += value;
			if (grn > 255)
			{
				grn = 255;
			}
			blu += value;
			if (blu > 255)
			{
				blu = 255;
			}
			PutRGB (image, i, j, red, grn, blu);
		}
	}
	return (image);
	}

IMAGE *AdjustContrast(IMAGE *image, double percent)
	{
        int i, j;
        unsigned red, grn, blu;
	double redtemp, grntemp, blutemp;
        unsigned Rows = GetRows (image);
        unsigned Cols = GetCols (image);
        for (i = 0; i < Rows; i++)
        {
                for (j = 0; j < Cols; j++)
                {
                        GetRGB (image, i, j, &red, &grn, &blu);
                        redtemp = (((double)red-128)*(percent/100));
			redtemp += 128;
			if (redtemp < 0)
				redtemp = 0;
			if (redtemp > 255)
				redtemp = 255;
                        red = (unsigned)redtemp;
                        grntemp = (((double)grn-128)*(percent/100));
			grntemp += 128;
			if (grntemp < 0)
				grntemp = 0;
			if (grntemp > 255)
				grntemp = 255;
                        grn = (unsigned)grntemp;
                        blutemp = (((double)blu-128)*(percent/100));
			blutemp += 128;
			if (blutemp < 0)
				blutemp = 0;
			if (blutemp > 255)
				blutemp = 255;
                        blu = (unsigned)blutemp;
                        PutRGB (image, i, j, red, grn, blu);
                }
        }
        return (image);
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

