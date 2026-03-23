#include <stdio.h>
#include <math.h>
#include <unistd.h>

char b[65536]="\x1b[1;1H";
float t=0;
int l,o,i,m=255,frame;

int u(int A,int B,int C,int D,int E){return sprintf(b+l,
"\x1b[38;2;%d;%d;%dm%c%s",A,B,C,D,E%80>78?"\n":"");}

void e1(){for(l=6,b[7]=i=0;i<1840;){o=256*(cos(i%80/8.)+sin(i/320.)+t);l+=
sprintf(b+l,"\x1b[38;2;%d;%d;%dm%c%s",o&m,(o+128)&m,(o+196)&m,(o/4&63)+32,
i++%80>78?"\n":"");}}

void e2() {
	int x,y;

	for(l=6,b[7]=i=0;i<80*23;) {
		x=i%80;
		y=i/80;

		o=( (y-((x*frame*8)/256)) &
				(x+((y*frame*8)/256))) &0xf0;

//		l+=sprintf(b+l,"\x1b[38;2;%d;%d;%dm%c%s",
		l+=u(o&m,(o+128)&m,(o+196)&m,(32+(o>>4))&0x3f,i++);
//				i++%80>78?"\n":"");
	}

}


int main(int argc, char **argv) {

	frame=-4096/8;

	while(1) {
		e2();
		write(1,b,l);
		usleep(m<<7);
		frame++;
		t=t+.005;
	}
	return 0;
}

