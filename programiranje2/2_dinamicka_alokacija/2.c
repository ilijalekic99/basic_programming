#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

typedef struct {
	int brojilac;
	int imenilac;

}raz;

int main(){
	
	int n;
	scanf("%d",&n);
	
	raz *r = malloc(n*sizeof(raz));
	
	double suma = 0,pom;	
	for(int i = 0; i<n; i++){
		scanf("%d %d",&r[i].brojilac,&r[i].imenilac);
		pom = ((double)r[i].brojilac/r[i].imenilac);
		suma+= pom;
	}
	suma = suma / n;
	
	for(int i = 0; i<n; i++){
		pom = ((double)r[i].brojilac/r[i].imenilac);
		if(pom > suma)
			printf("%d/%d\n",r[i].brojilac,r[i].imenilac);
	}

return 0;
}
