#include <stdio.h>
#include <math.h>
#include <unistd.h>

char b[65536]="\x1b[1;1H";
float t=0;
int l,o,i,m=255,f;

int u(int A,int B,int C,int D,int E){return sprintf(b+l,
"\x1b[38;2;%d;%d;%dm%c%s",A,B,C,D,E%80>78?"\n":"");}

void e3(){for(l=6,b[7]=i=0;i<1840;) {

int x,y;

y=i/80;
x=i%80;

o=(x-f)^y;

l+=u((o^x)&m,((y|o)+128)&m,((o>>3)+196)&m,32+((o>>4)&0x3f),i++);}}

/*

checkers_forever:

	inc	FRAME				; 2

	ldx	#39				; 2
yloop:
	ldy	#39				; 2
xloop:
;	sec					; 1
	tya					; 1
	sbc	FRAME				; 2
	;sta	X2				; 2
	sta	COLOR				; 2
	txa					; 1
	sbc	#0				; 2

;	eor	X2				; 2
	eor	COLOR				; 2
;	ora	#$DC				; 2
;	adc	#1				; 2

;	sta	COLOR

;	jsr	SETCOL				; 3

	txa		; A==Y1			; 1
	jsr	PLOT	; (X2,Y1)		; 3

	dey					; 1
	bpl	xloop				; 2

	dex					; 1
	bpl	yloop				; 2

	bmi	checkers_forever		; 2

*/


int main(int argc, char **argv) {

	f=-512;

	while(1) {
		e3();
		write(1,b,l);
		usleep(m<<7);
		f++;
		t=t+.005;
	}
	return 0;
}
