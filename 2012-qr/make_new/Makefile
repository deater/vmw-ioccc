CFLAGS = -O2 -Wall
CC = gcc

all:	rules make_string result.h url.h

make_string:	make_string.o
	$(CC) $(LFLAGS) -o make_string make_string.o

make_string.o:	make_string.c
	$(CC) $(CFLAGS) -c make_string.c

rules:	rules.o
	$(CC) $(LFLACS) -o rules rules.o

rules.o:	rules.c
	$(CC) $(CFLAGS) -c rules.c

out1.png:	rules.c
	qrencode -s1 < rules.c -o out1.png

out1.xpm:	out1.png
	convert out1.png out1.xpm

result.h:	out1.xpm make_string
	./make_string < out1.xpm > result.h

url.png:	url
	qrencode -s1 < url -o url.png

url.xpm:	url.png
	convert url.png url.xpm

url.h:	url.xpm make_string
	./make_string < url.xpm > url.h

sigtest:	sig.png
	zbarimg sig.png

sig.png:	sig.ans
	../../../ansi2gif-0.9.14/ansi2png --ysize auto --png sig.ans sig.png

sig.ans:	sig
	./sig > sig.ans

sig:	sig.o
	$(CC) $(LFLAGS) -o sig sig.o

sig.o:	sig.c
	$(CC) $(CFLAGS) -c sig.c

clean:	
	rm -f *~ *.o *.png *.xpm *.ans sig url.h result.h rules make_string short out.c



