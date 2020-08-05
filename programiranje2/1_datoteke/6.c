#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int main(){
	
	FILE *f = fopen("ulaz.txt","r");
	if(f == NULL)
		greska();
	
	FILE* g = fopen("izlaz.txt","w");
	
	int n;
	fscanf(f,"%d",&n);
	
	char* rec = malloc(n*sizeof(f));
	char pom[50];
	
	fscanf(f,"%s",rec);
	strcpy(pom,rec);
	printf("%s ",rec);
	
	for(int i = 2; i < n; i++){
		fscanf(f,"%s",rec);
		printf("%s ",rec);
		
		if(strstr(rec,pom))
			fprintf(g,"%s ",rec);
	}
	
fclose(f);
fclose(g);
return 0;
}
