#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int main(){ 
	
	FILE *f = fopen("ulaz.txt","r");
	FILE *g = fopen("izlaz.txt","w");
	
	if(f == NULL)
		greska();
	
	char c;
	
	while(fscanf(f,"%c",&c) != EOF)
		fprintf(g,"%c",c);
	
	
	
fclose(f);
fclose(g);
return 0;
}
