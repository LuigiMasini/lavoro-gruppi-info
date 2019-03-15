#include <stdio.h>
#include <stdlib.h>

int menu(void);
int bonus(void);


int main(){
	//scritte principali che non verranno mai ripetute
	menu();
}


/*TODO
 - reinserimento opzione menu a modo mio
 * ordine
 - recursione menù invece di iterazione
 * pulire e ordinare input e output (dispersivo, acapo acaso, troppi)
 * voce 7 necessaria?
 * controllo inserimanto numeri in funzione
 * printf riga 29, english is better
 - non funziona menù 6
 * si potrebbe usare enum per le opzioni
 *
 */

int menu(){
	int opz;
	
	printf("Salve Utente,\n"
	"Questo programma permette di creare una figura tra quelle proposte, e di personalizzarla modificandone proporzioni o colore.\n\n"
	"Ecco le opzioni:\n\n"
	"F1 F2 F3 F4 F5 menu bonus(6) credits(7)\n\n"
	"Inserire il numero dell'opzione desiderata");
	scanf("%d",&opz);
	switch (opz){
		case 0: exit(0);//o return, è la stessa cosa in questo caso
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6: printf("BENVENUTO NEL MENU BONUS: -va bene, tieniti pure i tuoi segreti\n");
			bonus();
			break;
			
		case 7: printf("\n*Programmatori: Luigi Masini, Federico Negro\nSuddivisione del lavoro:\nMasini:\nNegro:\nCollab:\n");
			break;
			
		default: printf("Si prega di inserire uno dei numeri corrispondenti alle differenti opzioni, sopra riportati");
	}
	printf("\n\n\n\n");
	menu();
}


int bonus(){
	int opzb;
	printf("Selezionare un opzione: OPZ1 OPZ2 ECC.. MENU BASE3");
	scanf("%d",&opzb);
	switch (opzb){
		case 0: exit(0);
		case 1:
			break;
		case 2:
			break;
		case 3: printf("-nothing strange here");	//torna a menù
			return 0;
			break;
		default:printf("\ninserire un opzione valida");
	}
	bonus();
}