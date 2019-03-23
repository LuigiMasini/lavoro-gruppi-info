#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#if defined __unix__ || defined linux
	char *cls = "clear";
#elif defined(_WIN32) || defined(WIN32)
	char *cls = "cls";
#endif

void menu(void);
int bonus(void);

void color();

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
				printf("Non e' un numero");
			printf("Inserisci la base\t");
			scanf("%s", &c);
		}
		while (c<48 || c>57 && ++wrong);
		lat=c-48;
		do {
			if(wrong)
				printf("non e' un numero");
			printf("Inserisci l'altezza:\t");
			scanf("%s", &a);
		}
		while (a<48 || a>57 && ++wrong);
		al=a-48;
	}
	else{ //figure
		do{
			if(wrong)
				printf("non e' un numero");
			printf("inserisci il lato:\t");
			scanf("%s", &c);
		}
		while(c<48 || c>57 && ++wrong);
		lat=c-48;
	}
	printf("\n\n");
}

int main(){
	//scritte principali che non verranno mai ripetute
	system("cls");
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
		case '6':system(cls);
			printf("BENVENUTO NEL MENU BONUS: -va bene, tieniti pure i tuoi segreti\n");
			bonus();
			break;

		case '7': printf("\n*Programmatori: Luigi Masini, Federico Negro\nSuddivisione del lavoro:\nMasini:\nNegro:\nCollab:\n");
			break;

		default: printf("Si prega di inserire uno dei numeri corrispondenti alle differenti opzioni");
	}

	menu();
}


int bonus(){
	char opzb;
	printf("1)You can't touch this\t2)opzioni colore\t3)torna al menu principale\t0)esci\nSelezionare un opzione: ");
	scanf("%s",&opzb);
	switch (opzb){
		case '0': exit(0);
		case '1':
#if defined __unix__ || defined linux
			system("./omino");
#elif defined(_WIN32) || defined(WIN32)
			system("omino.exe");
#endif
			break;
		case '2':
			color();
			break;
		case '3': printf("-nothing strange here");	//torna a menù
			return 0;
		default:printf("\ninserire un opzione valida");
	}
	bonus();
}
//colori
void color(){
#if defined __unix__ || defined linux
	printf("non disponibile per sistemi unix\n\n");
#elif defined(_WIN32) || defined(WIN32)
	int wrong=0;
	char opzc;
	do {
			if(wrong)
				printf("Non e' un numero");
			printf("\n\nOPZIONI COLORE\n1)nero\t2)blu\t3)verde\n4)turchese\t5)rosso\t6)viola\n7)giallo\t8)bianco\nSelezionare un opzione:\t");
			scanf("%s", &opzc);
		}
		while (opzc<48 || opzc>57 && ++wrong);
		wrong=opzc-48;
	switch (wrong){
		case 1: system("color 08");
			break;
		case 2: system("color 18");
			break;
		case 3: system("color 20");
			break;
		case 4: system("color 38");
			break;
		case 5: system("color 40");
			break;
		case 6: system("color 57");
			break;
		case 7: system("color 60");
			break;
		case 8: system("color 70");
			break;
		default: printf("selezionare una tra le opzioni di colore esposte");
			color();
			break;
	}
#endif
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
