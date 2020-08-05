 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 
 #define MAX_I 21
 
  void greska()
 {
	fprintf(stderr, "-1");
	exit(EXIT_SUCCESS);
 }
 
 //Definicija strukture student
 typedef struct {
	char ime[MAX_I];
	char prezime[MAX_I];
	char smer;
	float prosek;
 } STUDENT;
 
 //Funkija poredjenja koja ce se koristiti za pronalazak 
 //studenta sa zadatim prezimenom, u nizu studenata
 //sortiranih po prezimenu.
 int poredi(const void* a, const void *b)
 {
	char* pr = (char*)a;
	STUDENT s = *(STUDENT*)b;
	return strcmp(pr, s.prezime);
 }
 
 /*Funkcija koja binarnom pretragom 
 pronalazi prvog studenta sa zadatim prezimenom*/
 int binarna_rekurzivno(STUDENT* niz, int l, int d, char* pr)
 {
	if(l > d)
		return -1;
	
	int s = l + (d-l)/2;
	int rez = strcmp(niz[s].prezime, pr);
	if(rez == 0)
	{
		if(s == 0)
			return s;
		else{
			if(strcmp(niz[s-1].prezime, pr) == 0)
				return binarna_rekurzivno(niz, l, s-1, pr);
			else
				return s;
			}
	}
	else if(rez > 0)
		return binarna_rekurzivno(niz, l, s-1, pr);
	else
		return binarna_rekurzivno(niz, s+1, d, pr);
 }
 
 int main(){
 
/*Otvaramo datoteku studenti.txt za citanje*/
FILE* ulaz = fopen("studenti.txt", "r");
if(ulaz == NULL)
	greska();
	
STUDENT* niz;
char trazeno_prezime[MAX_I];

//Citamo iz fajla broj studenata
int n;
fscanf(ulaz, "%d", &n);

//Alociramo prostor za n studenata
niz = malloc(n*sizeof(STUDENT));
if(niz == NULL)
	greska();
	
//Informacije o studentima smestamo u niz	
int i;
for(i=0; i<n; i++)
{
	fscanf(ulaz, "%s%s %c%f", niz[i].ime, niz[i].prezime, &niz[i].smer, &niz[i].prosek);
}

//Ucitavamo trazeno prezime
scanf("%s", trazeno_prezime);

//Pronalazimo studenta sa trazenim prezimenom koriscenjem funckije bsearch
STUDENT* s = bsearch(trazeno_prezime, niz, n, sizeof(STUDENT), poredi); 
if(s == NULL)
	printf("BSEARCH: NEMA\n\n");
else{
	printf("BSEARCH: %s %s %c %.2f\n\n", s->ime, s->prezime, s->smer, s->prosek);
}

//Pronalazimo prvog studenta sa zadatim prezimenom koriscenjem nase funkcije
int poz = binarna_rekurzivno(niz, 0, n-1, trazeno_prezime);

//Ispisujemo informacije o svim studentima sa zadatim prezimenom:
if(poz == -1)
	printf("-\n");
else{
	printf("Svi studenti sa prezimenom %s:\n", trazeno_prezime);
	while(1)
	{
		if( strcmp(niz[poz].prezime, trazeno_prezime) != 0 || poz == n )
			break;
		printf("%s %s %c %.2f\n", niz[poz].ime, niz[poz].prezime, niz[poz].smer, niz[poz].prosek);
		poz++;
	}
}

free(niz);
fclose(ulaz);
 return 0;
 }
