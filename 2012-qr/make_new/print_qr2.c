#include <stdio.h>
void b(int x){while(x>-1)printf("\033[4%dm  ",x%2*7),x-=2;}char k,*p="l1f41mm6"
"5mm5OU5m5_55m5555mmGUml1ED1ooG_ol\\lDClN:eml9niiobTQOm8dlYoo=HUmmaNEnCDY[l1G@"
"7oo975l1>UImmSG3m5`@Om5<OGm5__5mm4S_l1DTi";void B(int x){b(x);b(0);puts("");}
int main(){B(65);while(*p){for(k=30;k--;)b((*p-48>>k%6)&1),p+=!(k%6);B(5);}}
  //return 0;



