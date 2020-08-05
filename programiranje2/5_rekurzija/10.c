#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int rez(int n){
	if(n == 0)
		return 0;
	
	int levo = rez(n/10);
	
	if(n%2)
		return levo*100 + (n%10)*10;
	else levo*10 + n%10;
	
}

int main(){
	int n;
	scanf("%d",&n);
	
	printf("%d",rez(n));

return 0;
}
