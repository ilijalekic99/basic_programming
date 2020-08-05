#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int main(){
	
	FILE *f = fopen("ulaz.txt","r");
	if(f == NULL)
		greska();
	
	int i = 1;
	double broj;
	char *ime = malloc(20*sizeof(char));
	char *prezime = malloc(20*sizeof(char));
	
	while(fscanf(f,"%d. %s %s %lf",&i,ime,prezime,&broj) != EOF){
		printf("%s %s\n",ime,prezime);
		i++;
	}
	
free(ime);
free(prezime);
fclose(f);
return 0;
}
