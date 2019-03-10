
#include <stdio.h>

int main()
{
    int menu=1,opz,opzb;
    
    while(menu==1)
    {
        printf("Salve Utente,\n"
		"Questo programma permette di creare una figura tra quelle proposte, e di personalizzarla modificandone proporzioni o colore.\n\n"
		"Ecco le opzioni:\n\n"
		"F1 F2 F3 F4 F5 menu bonus(6) credits(7)\n\n"
		"Inserire il numero dell'opzione desiderata");
        scanf("%d",&opz);
        while(opz>7||opz<1)
        {
            printf("Si prega di inserire uno dei numeri corrispondenti alle differenti opzioni, sopra riportati");
         }
         switch (opz){
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
             case 6:menu==2;
                    while(menu==2)
                    {
                        printf("BENVENUTO NEL MENU BONUS: -va bene, tieniti pure i tuoi segreti\nSelezionare un opzione: OPZ1 OPZ2 ECC.. MENU BASE3");
                        scanf("%d",&opzb);
                        while(opzb<0||opzb>3)
                        {printf("\ninserire un opzione valida");
                                scanf("%d",&opzb);
                        }
                        switch (opzb){
                            case 1:
                                   break;
                            case 2:
                                   break;
                            case 3:menu==1;
                            printf("-nothing strange here");
                                   break;
                    }
                    break;
             case 7:printf("\n*Programmatori: Masini Luigi, Negro Federico\nSuddivisione del lavoro:\nMasini:\nNegro:\nCollab:\n");
                    break;
         }
    }
        printf("\n\n\n\n");
    }
    return 0;
}


/*TODO
 * reinserimento opzione menu a modo mio
 * ordine
 * recursione menù invece di iterazione
 * pulire e ordinare input e output (dispersivo, acapo acaso, troppi)
 * voce 7 necessaria?
 * controllo inserimanto numeri in funzione
 * printf riga 34, english is better
 * non funziona menù 6
 * 
 */