CC = cc
C_FLAGS = -O2 -I/usr/X11R6/include
L_FLAGS = -L/usr/X11R6/lib -lGL -lGLU -lX11

all:	cube

warn:	cube.c verify_length
	verify_length cube.c
	$(CC) -Wall $(C_FLAGS) -c cube.c
	$(CC) -o cube cube.o $(L_FLAGS)

cube:	cube.o
	$(CC) -o cube cube.o $(L_FLAGS)

cube.o:	cube.c 
	$(CC) $(C_FLAGS) -c cube.c

verify_length:	verify_length.c
	$(CC) $(C_FLAGS) -o verify_length verify_length.c

clean:
	rm -rf core cube verify_length *.o *~ *.ps 
