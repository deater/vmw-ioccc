/*   Vince Weaver -- vince@deater.net -- http://www.deater.net/weave   */

#include   <stdio.h>
  int        main
   (){      char
    t,a[   4]=
     "\\_/|";
       int

k=0,i=1,c[12]={0,
     1180*
     1000+
     288,0
     ,0,41
     *100,
1048*1000+576,65*

1000         +568,
542*10*      1*100
+976 ,737*   1*100
+36,    1180*1000+
288,       16,542*
1000          +976

  },j;while(k<3){
 for(j=0
,t=0;j
<4;j++
 )t+=((c
  [k*4+j]&i)!=0)*

a[j];i*=2;putchar
(t?t
:32-22*(i<0));
if(i
<0)i
=1,k++;}return 0;}
