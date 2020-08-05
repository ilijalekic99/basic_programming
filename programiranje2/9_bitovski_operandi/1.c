#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

void print_bits(int n){
	unsigned mask = 1 << (sizeof(int)*8-1);
	
	while(mask){
		mask & n ? printf("1") : printf("0");
		mask >>= 1;
	}
	putchar('\n');
}

int main(){
	int n;
	
	scanf("%d",&n);
	
	print_bits(n);

return 0;
}
