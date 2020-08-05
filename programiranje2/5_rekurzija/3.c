#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}
int rez(int x){
	if(x < 10)
   	return x;
  
  	int najveca_levo = rez(x/10);
  
  	if(x%10 > najveca_levo)
    	  return x%10;
  	else
    	  return najveca_levo;

}


int main(){	
	int n;
	
	scanf("%d",&n);
	
	printf("%d\n",rez(n));

return 0;
}
