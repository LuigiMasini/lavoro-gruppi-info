#include <stdio.h>

int main() {
	int l;
	scanf("%d", &l);
	for(int i=0; i<l; i++){
		for(int j=0; j<l; j++)
			printf("* ");
		putchar('\n');
	}
}