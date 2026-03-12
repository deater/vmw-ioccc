#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
char b[1<<20]="\x1b[1;1H",*I="/usr/bin/aplay",*p;float t;FILE*P;int s=1<<16,l
,o,i,m=255,f=0,Z,i,x,y,z;
int main(int argc, char **argv) {Z=(1<<20)-s;
for(i=0;i<Z;i++)b[i+s]=(i>>2|3*i|i>>8)*9+4*((i&i>>12)|i>>7);
if(!fork()){if((P=fopen(I,"r"))){fclose(P);P=popen(I,"w");
for(;;)if(P)fwrite(&b[s],Z,1,P);}exit(1);}else while(1) {t=++f/200.;
for(l=6,b[7]=i=0;i<1840;){x=i%80;y=i/80;z=(f>>8)&0x4;switch((f>>8)&0x3){
case 0:o=(y-x*f/32)&(x+i*f/2560)&240;break;case 1:o=256*(cos(x/8.)+
sin(i/320.)+t);break;case 2:o=(x-f)^y;break;case 3:x-=40;y-=12;o=x*x+y*y+f;}
l+=sprintf(b+l,"\x1b[38;2;%d;%d;%dm%c%s",o&m,(o+128)&m,(z?o>>3:o+196)&m,32+
((o>>4)&63),i++%80>78?"\n":"");}write(1,b,l);usleep(s/2);}return 0;}
