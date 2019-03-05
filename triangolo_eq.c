#include <stdio.h>

int main(){
	int l, i, j;
	scanf("%d", &l);
	for(i=0; i<l; i++){
        for(j=i; j<l; j++)
			printf(" ");
		for(j=i+1;j;j--)
			printf("* ");

		putchar('\n');
	}
}
