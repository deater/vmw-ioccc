CC = gcc
CFLAGS = -Wall -O2
LFLAGS =

all:	reversed

reverse:	reverse.o
	$(CC) $(LFLAGS) -o reverse reverse.o

reverse.o:	reverse.c
	$(CC) $(CFLAGS) -c reverse.c


reversed:	reversed.o
	$(CC) $(LFALGS) -o reversed reversed.o

reversed.o:	reversed.c
	$(CC) $(CFLAGS) -c reversed.c

reversed.c:	reverse
	- ./reverse < reverse.c > reversed.c

clean:	
	rm -f *~ *.o reverse reversed reversed.c
