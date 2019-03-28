#include <stdio.h>
#include <stdlib.h>

// void main(){
// 	printf("\033[1;31mbold red text\033[0m\n");
// 	
// }

void main(){
	
	system("oldps1=\"$PS1\"");
	system("echo $PS1");
	system("echo $oldps1");
	
	do {
		// 	printf("non disponibile per sistemi unix\n\n");
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
		char *str;
		switch (wrong){
			case 1: system("PS1=\"$oldps1\"");
			break;
			case 2: str = "export PS1=\"\\e[34m $oldps1 \\e[m\"";
				printf("%s", str);
				system(str);
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
		}
	}
	while(1);
}