CC = gcc
CFLAGS = -Wall -O2
CFLAGS_UNDEFINED = -Wall -O

all:	clever_sig qr_sig vince_sig vince_vince


clever_sig:	clever_sig.o
	$(CC) -o clever_sig clever_sig.o

clever_sig.o:	clever_sig.c
	$(CC) $(CFLAGS_UNDEFINED) -c clever_sig.c


vince_sig:	vince_sig.o
	$(CC) -o vince_sig vince_sig.o

vince_sig.o:	vince_sig.c
	$(CC) $(CFLAGS_UNDEFINED) -c vince_sig.c


vince_vince:	vince_vince.o
	$(CC) -o vince_vince vince_vince.o

vince_vince.o:	vince_vince.c
	$(CC) $(CFLAGS_UNDEFINED) -c vince_vince.c


qr_sig:	qr_sig.o
	$(CC) -o qr_sig qr_sig.o

qr_sig.o:	qr_sig.c
	$(CC) $(CFLAGS) -c qr_sig.c


clean:	
	rm -f *.o *~ clever_sig qr_sig vince_sig vince_vince
