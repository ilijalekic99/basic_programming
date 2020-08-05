#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int main(){
	int x,k;
	
	scanf("%d%d",&x,&k);
	
	unsigned mask = 0;
	unsigned a = 1;
	
	mask = mask | a;
	
	mask <<= k;
	
	if(mask & x)
		printf("DA");
	else printf("NE");	

return 0;
}
