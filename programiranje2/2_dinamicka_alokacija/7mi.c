#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char puno_ime[101];
	int ocene[10];
	int broj_ocena;
	double prosek;
}STUDENT;

int najveci_pr(STUDENT *niz, int n){
	
	double max = 0;
	int poz;

	for(int i = 0; i<n; i++){
		niz[i].prosek = 0;
		for(int j = 0; j<niz[i].broj_ocena; j++){
			niz[i].prosek += niz[i].ocene[j];
		}
		niz[i].prosek /= niz[i].broj_ocena;

		if(niz[i].prosek > max){
			max = niz[i].prosek;
			poz = i;
		}
	}
	return poz;
}

void ispisi(const STUDENT *s){
	printf("%s %.2lf\n", s->puno_ime, s->prosek);
}

int main(){

	FILE *f = fopen("ulaz.txt","r");
	if(f == NULL){
		printf("-1");
		return -1;
	}

	int n;
	fscanf(f,"%d",&n);

	STUDENT *niz = malloc(n*sizeof(STUDENT));
	if(niz == NULL){
		printf("-1");
		return -1;
	}

	for(int i = 0; i<n; i++){
		char ime[101];
		char prezime[101];

		fscanf(f,"%s %s",ime,prezime);
		strcpy(niz[i].puno_ime, ime);
		strcat(niz[i].puno_ime, " ");
		strcat(niz[i].puno_ime, prezime);

		int tmp;
		for(int cnt = 0; ; cnt++){
			fscanf(f,"%d",&tmp);
			if(tmp == 0){
				niz[i].broj_ocena = cnt;
				break;
			}
			niz[i].ocene[cnt] = tmp;
		}
	}

	ispisi(&niz[najveci_pr(niz,n)]);

	fclose(f);
	return 0;
}