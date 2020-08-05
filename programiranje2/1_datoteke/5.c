/* ovo je resenje gde se sve reci iz datoteke ucitavaju u niz, a onda se iz niza uklanjaju duplikati, 5_2.c je resenje gde se vec prilikom citanja reci iz datoteke uklanjaju duplikati, tako da u nizu nema ponavljanja reci */  

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RECI 256
#define MAX_DUZINA 51
#define MAX_IME 21

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(){

  char ime[MAX_IME];
  char niz_reci[MAX_RECI][MAX_DUZINA];

  ///Ucitavamno ime datoteke sa standardnog ulaza
  scanf("%s", ime);
  FILE* ulaz;

  //Otvaramo fajl za citanje
  ulaz = fopen(ime, "r");
  if(ulaz == NULL)
    greska();

  //Citamo broj reci iz fajla
  int n;
  fscanf(ulaz, "%d", &n);
  if(n < 0 || n > MAX_RECI)
    greska();

  //Ucitavamo n reci u niz reci
  int i;
  for(i=0; i<n; i++)
  {
    fscanf(ulaz, "%s", niz_reci[i]);
    printf("%s ", niz_reci[i]);
  }

  //U rez.txt ispisujemo niz bez duplikata
  FILE* izlaz = fopen("rez.txt", "w");
  if(izlaz == NULL)
    greska();

  int k, ind = 0;
  for(i=0; i<n; i++)
  {
    ind = 0;
    for(k=0; k<i; k++)
    {
      if(strcmp(niz_reci[k], niz_reci[i]) == 0)
      {
        ind = 1;
        break;
      }
    }
    if(!ind)
      fprintf(izlaz, "%s\n", niz_reci[i]);
  }
  
  fclose(ulaz);
  fclose(izlaz);
  return 0;
}
