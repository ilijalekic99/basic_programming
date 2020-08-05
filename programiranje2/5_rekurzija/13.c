#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int f3(int x){
	if(x == 0)
		return 0;
	
	int r = f3(x/10);
	
	if((x/10)%10 == 2 && x%2 == 1)
		return r;
	else
		return r*10 + x%10;
}

int main(){
	int n;
	scanf("%d",&n);
	
	printf("%d\n",f3(n));

return 0;
}
