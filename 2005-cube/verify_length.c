/* Short program to test if the program fits within the IOCCC */
/* size constraints.  Most of the code is taken from the      */
/* mkentry.c file which bears the following copyright:        */

/*
 * Copyright (c) Leonid A. Broukhis, Simon Cooper, Landon Curt Noll and
 * Peter Seebach, 2004.
 *
 * All Rights Reserved.  Permission for personal, education or non-profit use
 * is granted provided this this copyright and notice are included in its
 * entirety and remains unaltered.  All other uses must receive prior
 * permission in writing from the contest judges.
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

#define MAX_COL 79		/* max column a line should hit */
#define MAX_PROGRAM_SIZE 4096	/* max program source size */
#define MAX_PROGRAM_SIZE2 2048	/* max program source size not counting
				   whitespace and {}; not followed by
				   whitespace or EOF */

int main(int argc, char **argv) {

   
    FILE *stream;		/* the opened file stream */
    struct stat statbuf;	/* the status of the open file */
    int count;			/* special count size */
    int c;			/* the character read */
    int control_m;		/* 1 ==> warn about trailing ^M's */   
   
    char filename[BUFSIZ];
   
   if (argc<2) {
      printf("Usage: %s filename\n\n",argv[0]);
      exit(1);  
   }
   
   strncpy(filename,argv[1],BUFSIZ);
   



    /*
     * open the program source input file
     */
    stream = fopen(filename, "r");
    if (stream == NULL) {
	fprintf(stderr, "cannot open program source file: %s: ",
	    filename);
	perror("");
	exit(7);
    }

    /*
     * determine the size of the file
     */
    if (fstat(fileno(stream), &statbuf) < 0) {
	fprintf(stderr, "cannot stat program source file: %s: ",
	    filename);
	perror("");
	return 1;
    }
    if (statbuf.st_size > MAX_PROGRAM_SIZE) {
	fprintf(stderr,
	    "FATAL: the program source file: %s, is %ld bytes long\n",
	    filename, (long) statbuf.st_size);
	fprintf(stderr,
	    "it may not be longer than %d bytes\n",
	    MAX_PROGRAM_SIZE);
	return 2;
    }

    /*
     * count the non-whitespace, non {}; followed by whitespace chars
     */
    control_m = 0;
    count = 0;
    c = 0;
    while ((c=fgetc(stream)) != EOF) {

	/* look at non-whitespace */
	if (isascii(c) && !isspace(c) && c != '\r') {
	    switch (c) {
	    case '{':		/* count if not followed by EOF or whitespace */
	    case '}':
	    case ';':
		/* peek at next char */
		c = fgetc(stream);
		if (c != EOF && isascii(c) && !isspace(c) && c != '\r') {
		    /* not followed by whitespace or EOF, count it */
		    ungetc(c, stream);
		    ++count;
		}
		break;
	    default:
		++count;
		break;
	    }

	/* look for trailing ^M's */
	} else if (c == '\r') {
	    /* peek at next char */
	    c = fgetc(stream);
	    if (c != EOF && c == '\n') {
		control_m = 1;
	    }
	    /* put the peeking char back */
	    ungetc(c, stream);
	}
    }

    

    /* look at the special size */
    if (count > MAX_PROGRAM_SIZE2) {
	fprintf(stderr,
	    "FATAL: the number of bytes that are non-whitespace, and\n"
	    );
	fprintf(stderr,
	    "        that are not '{', '}', ';' followed by whitespace\n"
	    );
	fprintf(stderr,
	    "        or EOF must be <= %d bytes\n",
	    MAX_PROGRAM_SIZE2);
	fprintf(stderr,
	    "        in %s, %d bytes were found\n",
	     filename, count);
	return 4;
    }

    /* warn about trailing ^M's */
    if (control_m) {
	fprintf(stderr,
    	    "\nWARNING: Trailing Control-M's (\\r or \\015) found.\n"
	    "\t If these chars result in a compilation failure,\n"
	    "\t your entry may be rejected\n\n");
    }

    /* return the open file */
    rewind(stream);
    
    return 0;
}
