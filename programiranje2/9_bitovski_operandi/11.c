#include <stdio.h>
#include <stdlib.h>


int main(){

	unsigned x;
	scanf("%u",&x);

	unsigned mask = 1;
	int i = 0;
	int cnt = 0;

	while(mask){
		if(mask & x)
			i++;
		else i = 0;

		if(i >= 2)
			cnt++;

		mask <<= 1;
	}

	printf("%d\n",cnt);

	return 0;
}