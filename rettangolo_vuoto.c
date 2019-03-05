#include <stdio.h>

main()
{
  int altezza,base,cont=0,c;
  
  scanf("%d %d",&base, &altezza);
  base=base-2;
  c=altezza;
  cont=base;
  for(altezza;altezza>0;altezza--){
    printf("* ");
    for(cont;cont>0;cont--){
      if(altezza==1||altezza==c)
	printf("* ");
      else
	printf("  ");
    }
    cont=base;
    printf("*\n");
  }
}