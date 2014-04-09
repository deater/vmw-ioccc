CC = gcc
CFLAGS = -Wall -O2
LFLAGS =

all:	qr

decode:	short

short:	short.o
	$(CC) $(LFAGS) -o short short.o

short.o:	short.c
	$(CC) $(CFLAGS) -c short.c

short.c:	short.png
	zbarimg -q --raw short.png > short.c

short.png:	short.ans
	../../ansi2gif-0.9.14/ansi2png --ysize auto --png short.ans short.png

short.ans:	qr
	./qr > short.ans


qr:	qr.o
	$(CC) $(LFLAGS) -o qr qr.o

qr.o:	qr.c
	$(CC) $(CFLAGS) -c qr.c

clean:	
	rm -f *~ *.o qr short short.c short.ans short.png


