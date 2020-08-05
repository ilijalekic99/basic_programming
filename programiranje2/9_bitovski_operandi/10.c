#include <stdio.h>
#include <stdlib.h>

int main(){

	unsigned x;
	scanf("%u",&x);

	unsigned mask = 1;
	int i = 0;

	while(mask){

		if(mask & x) i++;

		mask <<= 1;
	}

	if(i == 1)
		printf("JESTE");
	else printf("NIJE\n");

	return 0;
}