#include <stdio.h>
#include <stdlib.h>
#define max_rec 21

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int bin(char** niz, int l, int d, char* trazena){
	if(l > d)
		return -1;
	
	int s = (l+d)/2;
	int rez = strcmp(niz[s],trazena);
	
	if(rez == 0)
		return s;
	else if(rez > 0)
		return bin(niz,l,s-1,trazena);
	else return bin(niz,s+1,d,trazena);=
}

int poredi(const void* a, const void* b){
	return strcmp((char*)a, *(char**)b);
}

int main(){
	char** reci;
	char trazena[21];
	
	int n;
	scanf("%d",&n);
	
	reci = malloc(n*sizeof(char*));
	if(reci == NULL)
		greska();
	
	for(int i = 0; i<n; i++){
		reci[i] = malloc(max_rec);
		if(reci[i] == NULL)
			greska();
		scanf("%s", reci[i]);
	}
	
	scanf("%s",trazena);
	
	char** p = bsearch(trazena, reci, n, sizeof(char*), poredi);
	if(p == NULL)
		printf("NEMA\n");
	else printf("Bsearch: %ld\n", p-reci);
	
	int poz = bin(reci,0,n-1,trazena);
	printf("NASA: %d\n",poz);
	
	for(int i = 0; i<n; i++)
		free(reci[i]);
	free(reci);

return 0;
}
