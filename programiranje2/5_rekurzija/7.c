#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}


int obrni(int x, int p){
  if(x == 0)
    return 0;
  
  return (x%10)*pow(10, p) + obrni(x/10, p-1);
}

int main(){
	int n,p;
	
	scanf("%d%d",&n,&p);
	
	printf("%d",obrni(n,p));

return 0;
}
