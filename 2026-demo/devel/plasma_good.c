#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

char output[65536]="\x1b[1;1H";
int main(int argc, char **argv) {

	int length;
	double x,y,c,t=0;
	int o;
	char string[1024];

	while(1) {
		output[6]=0;

		for(y=0;y<24;y++) {
			for(x=0;x<80;x++) {
				c=cos(x/8)+sin(y/4)+t;
				o=(c*64.0);
				sprintf(string,
					"\x1b[38;2;%d;%d;%dm%c",
					(o&0x3f)*4,
					((o+32)&0x3f)*4,
					((o+48)&0x3f)*4,
					(o&0x3f)+' ');
				strcat(output,string);
			}
			strcat(output,"\n");
		}
		length=strlen(output);
		write(STDOUT_FILENO,output,length);
		usleep(30000);
		t=t+1.0/200.0;
	}
	return 0;
}
