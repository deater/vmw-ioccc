#include <math.h>
#include <stdio.h>
#include <unistd.h>
char b[1<<20]="\x1b[1;1H",*I="/usr/bin/aplay",*p;FILE *P;int s=1<<16,l,o,T,m=
255,a=256,Q=80,f=0,Z,_,z;int main(){Z=(1<<20)-s;for(T=0;T<Z;T++)b[T+s]=(T>>2|
3*T|T>>8)*9+4*((T&T>>12)|T>>7);if(!fork()){if((P=fopen(I,"r"))){fclose(P);;P=
popen(I,"w");for(;;)if(P)fwrite(&b[s],Z,1,P);}return 1;}else while(7){Z=++f>>
8;for(l=6,b[7]=T=0;T<23*Q;){_=T%Q;z=T/Q;o=Z&1?(Z&2?f+_*_+z*z-8*(-182+10*_+3*z
):a*(cos(_/8.)+sin(T/320.)+(float)f/200.)):(Z&2?(_-f)^z:(z-_*f/32)&(_+T*f/(a*
10))&240);l+=sprintf(b+l,"\x1b[38;2;%d;%d;%dm%c%s",o&m,(o+128)&m,(Z&4?o>>3:o+
196)&m,32+((o>>4)&63),T++%Q>78?"\n":"");}write(1,b,l);usleep(s/2);}return 0;}
