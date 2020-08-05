#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){

	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}


int main(){

	FILE* f = fopen("ulaz.txt","r");
	if(f == NULL)
		greska();

	int n;
	fscanf(f,"%d",&n);

	char A[256][51];

	for(int i = 0; i<n; i++)
		fscanf(f,"%s",A[i]);

	fclose(f);

	f = fopen("izlaz.txt","w");
	if(f == NULL)
		greska();

	int j,i;
	
	for(i = 0; i<n; i++){

		for(j = 0; j<i; j++){
			if(strcmp(A[i],A[j]) == 0)
				break;
		}
		if(i == j)
			fprintf(f,"%s ", A[i]);
	}

	return 0;
}