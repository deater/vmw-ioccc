#include <stdio.h>
#include <math.h>
#include <unistd.h>

char b[65536]="\x1b[1;1H";
float t=0;
int l,o,i,m=255;

void e(){for(l=6,b[7]=i=0;i<1840;){o=256*(cos(i%80/8.)+sin(i/320.)+t);l+=
sprintf(b+l,"\x1b[38;2;%d;%d;%dm%c%s",o&m,(o+128)&m,(o+196)&m,(o/4&63)+32,
i++%80>78?"\n":"");}}

int main(int argc, char **argv) {

	while(1) {
		e();
		write(1,b,l);
		usleep(m<<7);
		t=t+.005;
		break;
	}
	return 0;
}
