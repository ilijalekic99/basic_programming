#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int main(){
	int x;
	scanf("%d",&x);
	
	int rez = 0;
	
	unsigned mask = 1;
	
	while(mask > 0){
		if(x & mask)
			rez++;
		
		mask<<=1;
	}	
	
	printf("%d\n",rez);

return 0;
}
