#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>


/* by sierpinski on pouet */
int t2(int t) {
	return (t&t>>6&t*(t>>((t&65535)>>12)))+(3*t/4&t>>12&127)+(t*((t-2048)>>7&(t-2048)>>8&(t-2048)>>9&16)>>t/64);
}

/* by sierpinski on pouet */
int t3(int t) {
	return ((t>>10)%6*t&t>>6)^((t&t>>6)+(t|t>>8)+(t|t>>7)+(t|t>>9));
}

/* Tundrah (doesn't work?)
int t1(int t) {
	return (t>>5)|(t>>4)|(t%42*(t>>4)|357052691-(t>>4))/(t>>16)^(t|t>>4);
}
*/

/* 42 medly */
int t4(int t) {
	return t*(42&t>>10);
}

/* StephanShi */
int t5(int t) {
	return t*(t&16384?6:5)*(3+(3&t>>(t&2048?7:14)))>>(3&t>>9)|t>>2;
}

/* Neurofunk by StephanShi */
int t6(int t) {
	return t*(	(t&4096?t%65536<59392?7:t&7:16)+
			(1&t>>14))>>(3&-t>>(t&2048?2:10))|t>>(t&16384?t&4096?10:3:2);
}


/* LucasVB */
int t7(int t) {
//	return (t>>6|t<<1)+(t>>5|t<<3|t>>3)|t>>2|t<<1;
	return (((t>>6|t<<1)) + (t>>5|t<<3|t>>3) ) | (t>>2) | (t<<1);
}

/* PB95player/rrola */
int t8(int t) {
	return t*(0xCA98CA98CA98>>(t>>9&44)&15)|t>>8|40000/(t&4095);
}

/* rrola */
int t9(int t) {
	return t*(0xCA98CA98>>(t>>9&30)&15)|t>>8;
}


/* despair1 */
int t10(int t) {
	return ((((t>>6|t<<2)) | (t>>4|t<<3|t>>3) )) +
			t+((0x13FEB1978)>>(t>>9&30)&7)|t>>8;
}

/* despair2 */
int t12(int t) {
	return ((((t>>6|t<<2)) + ((0x13FEB1978)>>(t>>9&17)&7)))
		| (((t>>4|t<<3|t>>3) ));
}

/* tjoppen */
int t13(int t) {
	return (t>>7|t|t>>6)*10+4*(t&t>>13|t>>6);

}

/* despair3 */
int t1(int t) {
	return (t>>7|t|t>>6)*10+4*((t&t>>13)|t>>6);

}







int main(int argc, char**argv) {

FILE *P;
char *I="/usr/bin/aplay";
char *J="r.raw";
char *b;
int Z=704e3,s=0;


	int t;

	if (!(b=calloc(Z,1))) return 1;

	for(t=0;t<Z;t++) b[t]=t1(t);

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
