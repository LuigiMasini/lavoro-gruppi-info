/* in questo file ci sono le funzioni per stampare le figure:
 * 
 * quadrato
 * quadrato a metà
 * rettangolo vuoto
 * triangolo rettangolo
 * triangolo equilatero
 * 
 * viene assunto di base che i valori passati
 * siano corretti, controllo già nell'inserimento
 */
#include <stdio.h>
//BEGIN figure

void quad(int l){
	for(int i=0; i<l; i++){
		for(int j=0; j<l; j++)
			printf("* ");
		putchar('\n');
	}
}

void quad_meta(int l){
	for(int i=0; i<l; i++){
		for(int j=i+1;j;j--)
			printf("* ");
		for(int j=i; j<l; j++)
			printf("- ");
		putchar('\n');
	}
}

void rett(int base, int altezza){
	int c, cont;
	base-=2;
	c=altezza;
	for(;altezza>0;altezza--){
		printf("* ");
		cont=base;
		for(;cont>0;cont--){
			if(altezza==1||altezza==c)
				printf("* ");
			else
				printf("  ");
		}
		printf("*\n");
	}
}


void tri_eq(int l){
	for(int i=0; i<l; i++){
		int j;
		for(j=i; j<l; j++)
			printf(" ");
		for(j=i+1;j;j--)
			printf("* ");
		putchar('\n');
	}
}


void tri_ret(int l){
	for(int i=0; i<l; i++){
		for(int j=i+1;j;j--)
			printf("* ");
		putchar('\n');
	}
}
//END figure