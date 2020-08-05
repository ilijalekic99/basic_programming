#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int main(){
	int x,k;
	scanf("%d%d",&x,&k);
	
	if(k >= 32)
		greska();
	
	unsigned mask = 1;
	
	mask<<=k;
	
	x = x | mask;
	
	printf("%d\n",x);	

return 0;
}
