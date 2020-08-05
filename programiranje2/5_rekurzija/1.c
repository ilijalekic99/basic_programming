#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

void rek1(int a){
	if(a == 0)
		return;
		
	int pom = a % 10;
		
	rek1(a/10);
	
	printf("%d ",pom);
}

void rek2(int a){
	if(a == 0)
		return;
	
	int pom = a % 10;
	
	printf("%d ",pom);
	
	rek2(a/10);

}

int main(){
	int a;
	scanf("%d",&a);
	rek1(a);
	printf("\n");
	rek2(a);

return 0;
}
