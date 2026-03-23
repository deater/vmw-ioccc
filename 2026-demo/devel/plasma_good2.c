#include <stdio.h>
#include <math.h>
#include <unistd.h>

char b[65536]="\x1b[1;1H";

int main(int argc, char **argv) {

	int l,o,i;
	double t=0;

	while(1) {
		l=6;

		for(b[7]=i=0;i<1840;i++){
			o=64*(cos((i%80)/8.)+sin((i/80)/4.)+t);
			l+=sprintf(b+l,
				"\x1b[38;2;%d;%d;%dm%c",
				(o&0x3f)*4,
				((o+32)&0x3f)*4,
				((o+48)&0x3f)*4,
				(o&0x3f)+' ');
			if ((i%80)==79) b[l++]='\n';
		}
		write(1,b,l);
		usleep(30000);
		t=t+.005;

	}
	return 0;
}
