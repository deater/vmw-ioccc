#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

char b[1<<20]="\x1b[1;1H",*I="/usr/bin/aplay",*p;float t;FILE*P;
int s=1<<16,l,o,i,m=255,f=0,Z,i,x,y,z;
int u(){return sprintf(b+l,"\x1b[38;2;%d;%d;%dm%c%s",o&m,(o+128)&m,
(z?o>>3:o+196)&m,32+((o>>4)&63),i++%80>78?"\n":"");}

void e1(){z=0;o=256*(cos(x/8.)+sin(i/320.)+t);}
void e2(){z=0;o=(y-x*f/32)&(x+i*f/2560)&240;}
void e3(){z=1;o=(x-f)^y;}
void e4(){z=1;x-=40;y-=12;o=x*x+y*y+f;}

void (*effects[])()={e1,e2,e3,e4};

int main(int argc, char **argv) {
	Z=(1<<20)-s;
	for(i=0;i<Z;i++)b[i+s]=(i>>2|3*i|i>>8)*9+4*((i&i>>12)|i>>7);
	if(!fork()){if((P=fopen(I,"r"))){fclose(P);P=popen(I,"w");for(;;)if(P)
	fwrite(&b[s],Z,1,P);}exit(1);}

else while(1) {
		f++;
		t=f/200.;
		for(l=6,b[7]=i=0;i<1840;) {
		x=i%80;y=i/80;
		if (((f>>9)&3)==0) effects[3]();
		else if (((f>>9)&3)==1) e2();
		else e3();
		l+=u();
		}
		write(1,b,l);
		usleep(s/2);
	}
	return 0;
}
