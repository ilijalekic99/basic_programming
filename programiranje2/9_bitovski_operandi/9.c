#include <stdio.h>
#include <stdlib.h>


void print_bits(unsigned x){
	unsigned mask = 1 << (sizeof(int) * 8 - 1);	

	while(mask){
		mask & x ? printf("1") : printf("0");
		mask>>=1;
	}
	putchar('\n');
}	

unsigned mirror(unsigned x){
	
	unsigned pom = 1;
	unsigned mask = 0;
	int n = 0;

	while(1){
		if(n == 31)
			break;
		pom = pom & x;
		mask = mask | pom;
		mask <<= 1;
		x >>= 1;
		n++;
		pom = 1;
	}
	return mask;
}

int main(){

	unsigned x;
	scanf("%u",&x);

	unsigned k = mirror(x);

	print_bits(x);
	print_bits(k);

return 0;
}