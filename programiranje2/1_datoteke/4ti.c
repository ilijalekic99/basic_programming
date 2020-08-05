#include <stdio.h>
#include <stdlib.h>


void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int main(){

	int A[50][50];

	int vrsta,kolona;

	FILE* f = fopen("ulaz.txt","r");
	if(f == NULL)
		greska();

	fscanf(f,"%d %d",&vrsta,&kolona);

	if(vrsta > 50 || kolona > 50 || vrsta < 0 || kolona < 0)
		greska();

	for(int i = 0; i<vrsta; i++){
		for(int j = 0; j<kolona; j++){
			fscanf(f,"%d",&A[i][j]);
		}
	}

	fclose(f);

	int suma = 0;
	for(int i = 0; i<vrsta; i++){
		
		for(int j = 0; j<kolona; j++){
			suma = 0;
			for(int c = -1; c<2; c++){
				for(int b = -1; b<2; b++){
					if((c!=0 || b!=0) && (i+c >= 0) && (j+b >=0) && (i+c<vrsta) && (j+b < kolona))
						suma+=A[i+c][j+b];
				}
			}
			if(suma == A[i][j])
				printf("(%d, %d, %d)\n",i,j,suma);		
		}
	}



	return 0;
}