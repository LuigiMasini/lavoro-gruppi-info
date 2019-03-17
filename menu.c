#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void menu(void);
int bonus(void);

void quad(int);
void quad_meta(int);
void rett(int, int);
void tri_eq(int);
void tri_ret(int);

int lat, al;

void lato(bool tipo){
	int wrong=0;
	char c, a;
	if(tipo){ //rettangolo
		do {
			if(wrong)
				printf("NAN");
			printf("Inserisci la base\t");
			scanf("%s", &c);
		}
		while (c<48 || c>57 && ++wrong);
		lat=c-48;
		do {
			if(wrong)
				printf("NAN");
			printf("Inserisci la cazzo di altezza:\t");
			scanf("%s", &a);
		}
		while (a<48 || a>57 && ++wrong);
		al=a-48;
	}
	else{ //figure
		do{
			if(wrong)
				printf("NAN");
			printf("inserisci il porco demonio di lato:\t");
			scanf("%s", &c);
		}
		while(c<48 || c>57 && ++wrong);
		lat=c-48;
	}
	printf("\n\n");
}

int main(){
	//scritte principali che non verranno mai ripetute
	printf("Salve Utente,\n"
	"Questo programma permette di creare una figura tra quelle proposte, e di personalizzarla modificandone proporzioni o colore.\n\n");
	menu();
}


/*TODO
 * voce 7 necessaria?
 * controllo inserimanto numeri in funzione
 * si potrebbe usare enum per le opzioni
 *
 */

void menu(){
	char opz;
	printf("Funzioni programma:\n\n"
	"1)quadrato\t\t2)triangolo equilatero\n3)triangolo rettangolo\t4)rettangolo vuoto\n5)mezzo quadrato\t6)menu bonus\n7)credits\t\t0)uscire\n\n"
	"Scegli l'opzione:\t");
	scanf("%s",&opz);
	switch (opz){
		case '0': exit(0);//o return, è la stessa cosa in questo caso
		case '1':lato(0);
			quad(lat);
			break;
		case '2':lato(0);
			tri_eq(lat);
			break;
		case '3':lato(0);
			tri_ret(lat);
			break;
		case '4':lato(1);
			rett(lat, al);
			break;
		case '5':lato(0);
			quad_meta(lat);
			break;
		case '6':system("clear");
			printf("BENVENUTO NEL MENU BONUS: -va bene, tieniti pure i tuoi segreti\n");
			bonus();
			break;
			
		case '7': printf("\n*Programmatori: Luigi Masini, Federico Negro\nSuddivisione del lavoro:\nMasini:\nNegro:\nCollab:\n");
			break;
			
		default: printf("Si prega di inserire uno dei numeri corrispondenti alle differenti opzioni");
	}
	printf("\n\n\n");
// 	system("clear");
	menu();
}


int bonus(){
	char opzb;
	printf("Selezionare un opzione: OPZ1 OPZ2 ECC.. MENU BASE3");
	scanf("%s",&opzb);
	switch (opzb){
		case '0': exit(0);
		case '1':
			break;
		case '2':
			break;
		case '3': printf("-nothing strange here");	//torna a menù
			return 0;
		default:printf("\ninserire un opzione valida");
	}
	bonus();
}

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