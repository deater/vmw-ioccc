CC = gcc
CFLAGS = -Wall -O2
LFLAGS = -lm

all:	plasma_simple sierzoom_simple checkers_simple music random_music prog

###

prog:	prog.o
	$(CC) -o prog prog.o $(LFLAGS)

prog.o:	prog.c
	$(CC) $(CFLAGS) -c prog.c

###

music:	music.o
	$(CC) -o music music.o $(LFLAGS)

music.o:	music.c
	$(CC) $(CFLAGS) -c music.c

###

random_music:	random_music.o
	$(CC) -o random_music random_music.o $(LFLAGS)

random_music.o:	random_music.c
	$(CC) $(CFLAGS) -c random_music.c


###

checkers_simple:	checkers_simple.o
	$(CC) -o checkers_simple checkers_simple.o $(LFLAGS)

checkers_simple.o:	checkers_simple.c
	$(CC) $(CFLAGS) -c checkers_simple.c

###

plasma_simple:	plasma_simple.o
	$(CC) -o plasma_simple plasma_simple.o $(LFLAGS)

plasma_simple.o:	plasma_simple.c
	$(CC) $(CFLAGS) -c plasma_simple.c

###

sierzoom_simple:	sierzoom_simple.o
	$(CC) -o sierzoom_simple sierzoom_simple.o $(LFLAGS)

sierzoom_simple.o:	sierzoom_simple.c
	$(CC) $(CFLAGS) -c sierzoom_simple.c

###

clean:	
	rm -f plasma_simple sierzomo_simple checkers_simple music \
		random_music prog *~ *.o
