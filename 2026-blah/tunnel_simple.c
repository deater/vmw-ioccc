#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

char b[1<<20]="\x1b[1;1H",*I="/usr/bin/aplay",*p;float t;
int s=1<<16,l,o,i,m=255,f=0,Z,i;FILE*P;

int u(int A,int B,int C,int D,int E){return sprintf(b+l,
"\x1b[38;2;%d;%d;%dm%c%s",A&m,B,C,D,E%80>78?"\n":"");}

void e1(){o=256*(cos(i%80/8.)+sin(i/320.)+t);l+=
u(o,(o+128)&m,(o+196)&m,(o/4&63)+32,i++);}

void e2(){o=(i/80-i%80*f/32)&(i%80+i*f/2560)&240;
l+=u(o,(o+128)&m,(o+196)&m,(32+(o>>4))&0x3f,i++);}

void e3(){
o=(i%80-f)^i/80;l+=u(o,(o+128)&m,((o>>3)+196)&m,32+((o>>4)&0x3f),i++);}

void e4() {
	int x,y,xcoord,ycoord,value,value2;
	char depth;
	x=i%80; // Y
	y=i/80;	// X

	xcoord=(x-10)*2;
	ycoord=((y-10)*8)-12; // 24?

	depth=-9;

	while(1) {
		value=(ycoord*depth)>>8;
		value2=((xcoord+depth)*depth)>>8;

		depth--;
		if (!depth) break;

		value=(value^value2)+4;

		if ((value&0xf8)) break;
	}

	o=((depth-f)^value)&0x63;
	l+=u(o,(o+128)&m,((o>>3)+196)&m,32+((o>>4)&0x3f),i++);
}

int main(int argc, char **argv) {
	Z=(1<<20)-s;
	for(i=0;i<Z;i++)b[i+s]=(i>>2|3*i|i>>8)*9+4*((i&i>>12)|i>>7);
	if(!fork()){if((P=fopen(I,"r"))){fclose(P);P=popen(I,"w");for(;;)if(P)
	fwrite(&b[s],Z,1,P);}exit(1);}

else while(1) {
		f++;
		t=f/200.;
		for(l=6,b[7]=i=0;i<1840;) {
		if (((f>>9)&3)==0) e4();
		else if (((f>>9)&3)==1) e2();
		else e3();
		}
		printf("%d\n",f);
		write(1,b,l);
		usleep(s/2);
	}
	return 0;
}
