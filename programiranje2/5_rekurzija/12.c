#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

void trougao(int n, int linija)
{
  if(linija > n)
    return;
  
  int i;
  for(i=0; i<n-linija; i++)
    printf(" ");
  
  for(i=0; i<linija; i++)
    printf("*");
  
  printf("\n");
  
  trougao(n, linija+1);
}

int main(){
	int n,lin = 0;
	
	scanf("%d",&n);	
	
	trougao(n,lin);
	
return 0;
}
