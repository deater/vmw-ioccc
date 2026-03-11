#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>


// orig
// p1=7,p2=1,p3=6,p4=10,p5=4,p6=13,p7=6;

// ok
// p1=8,p2=12,p3=1,p4=9,p5=9,p6=11,p7=11

// interesting
// p1=5,p2=14,p3=4,p4=3,p5=7,p6=13,p7=9

// owie
// p1=6,p2=9,p3=7,p4=8,p5=11,p6=0,p7=6

//hammer
// p1=14,p2=11,p3=4,p4=9,p5=4,p6=12,p7=3

// chow
// p1=6,p2=12,p3=7,p4=6,p5=12,p6=2,p7=8

// blip blip
//p1=4,p2=7,p3=5,p4=13,p5=14,p6=8,p7=7

// hypnotic
// p1=5,p2=8,p3=3,p4=12,p5=1,p6=3,p7=3

// beat
// p1=6,p2=4,p3=1,p4=6,p5=0,p6=14,p7=2

// really like
// p1=2,p2=3,p3=8,p4=9,p5=4,p6=12,p7=7

int main(int argc, char**argv) {


FILE *P;
char *I="/usr/bin/aplay";
char *J="r.raw";
char *b;
int Z=704e3,s=0;


	int t;

	if (!(b=calloc(Z,1))) return 1;


	int p1=7,p2=1,p3=6,p4=10,p5=4,p6=13,p7=6;


	srand(time(NULL));

	p1=rand()%15;
	p2=rand()%15;
	p3=rand()%15;
	p4=rand()%15;
	p5=rand()%15;
	p6=rand()%15;
	p7=rand()%15;


	printf("p1=%d,p2=%d,p3=%d,p4=%d,p5=%d,p6=%d,p7=%d\n",
		p1,p2,p3,p4,p5,p6,p7);

	/* baed on tjoppen  */
	for(t=0;t<Z;t++) b[t]=(t>>p1|p2*t|t>>p3)*p4+p5*((t&t>>p6)|t>>p7);

	if (!fork()){
		if ((P=fopen(I,"r"))) {
			fclose(P);
			P=popen(I,"w");
			s=1;
		}
		else{
			P=fopen(J,"w");
		}
		if (P) {
			fwrite(b,Z,1,P);
		}
		if (!s) fclose(P);
		else pclose(P);
		for(;;);
	}
	for(;;){

	}

	return 0;
}
