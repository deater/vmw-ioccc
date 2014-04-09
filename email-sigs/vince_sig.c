/*   Vince Weaver -- vince@deater.net -- http://www.deater.net/weave   */

main(){char t,a[4]="\\_/|";int k=0,i=1,c[12]={0,1180288,0,0,4100,1048576
,65568,542976,73736,1180288,16,542976},j;while(k<3){for(j=0,t=0;j<4;j++)
t+=((c[k*4+j]&i)!=0)*a[j];i*=2;putchar(t?t:32-22*(i<0));if(i<0)i=1,k++;}}
