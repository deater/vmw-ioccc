#include <stdio.h>
#include <unistd.h>
int main(int argc,char**argv){char*Z="#%i;2;%d;%d;%d\n",X[51200],O[]="-\n#%d";
int d,S,r,f=0,o,T,I,_=256;for(;;){for(r=0;r<51200;){T=13;L:d=r/_*++T;S=r%_-T;
o=S&_?(r%_+d)&255?r/_/16+32:27:(((S*T)|d)>>8)&(T+f);if(~S&_)if(~o&16)goto L;
X[r++]=o-16;}usleep(1e4);f++;puts("\n\033[1;1H\033Pq\n");for(S=0;S<96;S+=6)
printf(Z,S/6,S,S,S),printf(Z,S/6+16,S>25?S>72?97-S:25:S,S>72?25:S>42?S-48:
0,S<48?S<24?25:48-S:0);for(d=0;d<33;d++)for(o=0,*O='-';o<32;o++){for(r=0;
r<6;r++)                     for(I=0;I<_;I++)if(X[I+(d*6+r)*_]^~o)break;
if(r>5){     printf(O,o);    *O='$';for(I=0;I<_;I++){for(r=5,T=0;r>=0
;)T=T<<1                     | ( X [ I + ( d * 6 + r -- ) *_ ] ==o);
putchar (  T  +  '?'  )  ;  }  }  }  puts ( "\n\033\\\n" )  ;  }  }
