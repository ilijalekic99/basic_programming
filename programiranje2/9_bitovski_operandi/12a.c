#include <stdio.h>
#include <stdlib.h>


int main(){

	unsigned x,mask=1;
	scanf("%u",&x);

	int i = 0;

	while(mask){
		if(mask & x)
			i++;

		mask<<=1;
	}


	mask = 0;
	int pom = i;
	while(i > 0){
		mask = mask | 1;
		mask<<=1;
		i--;
	}

	mask <<= (30 - pom);

	printf("%u\n",mask);

	return 0;
}