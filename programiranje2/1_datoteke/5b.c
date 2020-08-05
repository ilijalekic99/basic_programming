/* resenje 5. zadatka gde se vec prilikom citanja reci iz datoteke uklanjaju duplikati, tako da u nizu nema ponavljanja reci */  

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 21
#define MAXR 256
#define MAXI 51

void greska(){
	fprintf(stderr, "-1");
	exit(EXIT_FAILURE);	

}

int main(){
char u[MAX], rec[MAXI], reci[MAXR][MAXI];
int i=0, j=0, id=0, n, br=0;

scanf("%s", u);

FILE *ulaz, *izlaz;
ulaz = fopen(u, "r");
if(ulaz==NULL)
	greska();

izlaz = fopen("rez.txt", "w");
if(izlaz==NULL)
	greska();

fscanf(ulaz, "%d", &n);

while(i<n){
	fscanf(ulaz, "%s ", rec);
	printf("%s ", rec);
	j=0;
	id=0;	
	while(j<br){
		if(strcmp(rec, reci[j])==0){
			id=1;
			break;
		}
		j++;
	}
	if(id==0){
		fprintf(izlaz, "%s ", rec);
		strcpy(reci[br++], rec);
	}
	i++;
}

fclose(ulaz);
fclose(izlaz);

}


