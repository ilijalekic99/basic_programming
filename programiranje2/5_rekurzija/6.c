#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

void rez(int x){
	if(x == 0)
		return;
	
	rez(x/16);
	
	if(x%16 < 10)
		printf("%d",x%16);
	else printf("%c",'A' + x%16 - 10);
}

int main(){
	int n;
	scanf("%d\n",&n);
	
	rez(n);

return 0;
}
