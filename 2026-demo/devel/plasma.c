#include <stdio.h>
#include <math.h>
#include <unistd.h>

unsigned char screen[80*24];

void dump_fb(void) {
	int x,y,c;

	for(y=0;y<22;y++) {
		for(x=0;x<80;x++) {
			c=screen[(y*80)+x];
			printf("%c[38;2;%d;%d;%dm",27,
				(c&0x3f)*4,
				((c+32)&0x3f)*4,
				((c+48)&0x3f)*4);
			c=(c&0x3f)+' ';
			printf("%c",c);
		}
		printf("\n");
	}
}

void cls(void) {

	printf("\n%c[1;1H",27);
}

int main(int argc, char **argv) {

	double x,y,c,t=0;

	while(1) {

		for(x=0;x<80;x++) {
			for(y=0;y<24;y++) {
				c=cos(x/128)+sin(y/128)+t;
				// printf("%lf\n",c);
				screen[(int)((y*80)+x)]=c*64;
			}
		}
		cls();
		dump_fb();
		usleep(30000);
		t=t+1.0/200.0;
	}
	return 0;
}
