#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
 
   char string[BUFSIZ],*result;
   int i,count;
   char j; 
   int xsize=0;

   while(1) {
      result=fgets(string,BUFSIZ,stdin);
      if (result==NULL) break;

      if (strstr(string,"columns")) {      
         result=fgets(string,BUFSIZ,stdin);
         if (result==NULL) break;
	 sscanf(string,"%*s %d",&xsize);
	 /* border of 4 on each side */
	 xsize/=6;
	 //	 printf("xsize=%d\n",xsize);
      }

      if (strstr(string,"pixels")) {
	 printf("\"");
	 
	 while(1) {
	    result=fgets(string,BUFSIZ,stdin);
            if (result==NULL) break;  
	    if (result[0]=='}') break;
	    if (result[0]!='\"') break;
	    
	    j=0;
	    count=0;
	    for(i=1;i<strlen(result);i++) {
	       if (result[i]=='\"') break;
	       
	       j<<=1;
	       if (result[i]=='.') j|=1;
	       count++;
	       
	       if (count==6) {
		  count=0;
		  if (j+0x30=='\\') printf("\\\\");
		  else printf("%c",j+0x30);
		  j=0;
	       }
	    }
	 }
	 printf("\"\n");
	 break;
      }
      
   }
   
   return 0;
}
