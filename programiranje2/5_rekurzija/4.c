#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int ukloni(int x,int c){
	if(x == 0)
    return 0;
  
  int levi_deo = ukloni(x/10, c);
  
  if(x%10 == c)
    return levi_deo;
  else
    return levi_deo*10 + x%10;

}

int main(){
	int n,c;
	scanf("%d%d",&n,&c);
	
	printf("%d\n",ukloni(n,c));

return 0;
}
