#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>


char b[65536]="\x1b[1;1H";float t=0;int l,o,i,m=255,f=0,Z=704e3,s=0,i=0;
FILE *P;char *I="/usr/bin/aplay",*J="r.raw",*p;


int u(int A,int B,int C,int D,int E){return sprintf(b+l,
"\x1b[38;2;%d;%d;%dm%c%s",A&m,B,C,D,E%80>78?"\n":"");}

void e1(){for(l=6,b[7]=i=0;i<1840;){o=256*(cos(i%80/8.)+sin(i/320.)+t);l+=
u(o,(o+128)&m,(o+196)&m,(o/4&63)+32,i++);}}

void e2(){for(l=6,b[7]=i=0;i<1840;) {o=(i/80-i%80*f/32)&(i%80+i*f/2560)&240;
l+=u(o,(o+128)&m,(o+196)&m,(32+(o>>4))&0x3f,i++);}}

void e3(){for(l=6,b[7]=i=0;i<1840;) {
o=(i%80-f)^i/80;l+=u(o,(o+128)&m,((o>>3)+196)&m,32+((o>>4)&0x3f),i++);}}


int main(int argc, char **argv) {if(!(p=calloc(Z,1)))exit(1);
for(i=0;i<Z;i++)p[i]=(i>>2|3*i|i>>8)*9+4*((i&i>>12)|i>>7);
if(!fork()){if((P=fopen(I,"r"))){fclose(P);P=popen(I,"w");for(;;)if(P)
fwrite(p,Z,1,P);}exit(1);}

else while(1) {
		if (((f>>9)&3)==0) e1();
		else if (((f>>9)&3)==1) e2();
		else e3();
		printf("%d\n",f);

		write(1,b,l);
		usleep(m<<7);
		f++;
		t=t+.005;
	}
	return 0;
}
