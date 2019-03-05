#include <stdio.h>

int main(){
	int l;
	scanf("%d", &l);
	for(int i=0; i<l; i++){
		for(int j=i+1;j;j--)
			printf("* ");
		putchar('\n');
	}
}