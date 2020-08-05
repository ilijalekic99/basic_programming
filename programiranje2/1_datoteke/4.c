#include<stdio.h>
#include<stdlib.h>

#define MAX_DIM 50
void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(){

FILE* ulaz;
float A[MAX_DIM][MAX_DIM];

ulaz = fopen("matrica.txt", "r");
if(ulaz == NULL)
	greska();

int n, m;
fscanf(ulaz, "%d%d", &n, &m);
if(n <= 0 || n > MAX_DIM || m <= 0 || m > MAX_DIM)
	greska();

//Ucitavanje matrice
int i, j;
for(i=0; i<n; i++){
	for(j=0; j<m; j++){
		fscanf(ulaz, "%f", &A[i][j]);	
	}
}

//Provera
int k, l;
float suma = 0;
for(i=0; i<n; i++){
	for(j=0; j<m; j++)
	{
		//Provera za poziciju (i,j):
		suma = 0;
		for(k=i-1; k<=i+1; k++){
			for(l=j-1; l<=j+1; l++){
				if(k>=0 && k<n && l>=0 && l<m)
					suma += A[k][l];			
			}
		}
		suma -= A[i][j];
		if(A[i][j] == suma)
			printf("(%d, %d, %g)\n", i, j, A[i][j]);
	}
}

fclose(ulaz);
return 0;
}
