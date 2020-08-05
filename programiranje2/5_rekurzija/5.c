#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int rez(int a){
	if(a == 0)
		return 0;
	
	if(a % 2 == 0)
		return rez(a/10) + 1;
	else return rez(a/10);
}

int main(){
	int a;
	scanf("%d",&a);
	
	printf("%d\n",rez(a));	

return 0;
}
