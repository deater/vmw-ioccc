CFLAGS = -Wall -O2
LFLAGS = -lm

all:	plasma_simple

plasma_simple:	plasma_simple.o
	$(CC) -o plasma_simple plasma_simple.o $(LFLAGS)

plasma_simple.o:	plasma_simple.c
	$(CC) $(CFLAGS) -c plasma_simple.c

clean:	
	rm -f plasma_simple *~ *.o
