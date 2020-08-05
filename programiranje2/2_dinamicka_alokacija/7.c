#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_IME 101
#define MAX_OCENE 10

typedef struct {
  char puno_ime[MAX_IME];
  unsigned ocene[MAX_OCENE];
  int broj_ocena;
  float prosek;
} STUDENT;

void greska()
{
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

//Funkcija koja pronalazi studenta sa najvecim prosekom
int najveci_prosek(STUDENT* niz, int n){
  int i, pozicija = 0;
  float p = niz[0].prosek;
  for(i=1; i<n; i++)
    if(niz[i].prosek > p){
      pozicija = i;
      p = niz[i].prosek;
    }
  
  return pozicija;
}

//Funkcija koja ispisuje podatke o prosledjenom studentu
void ispisi(const STUDENT* s){
  printf("%s %.2f\n", s->puno_ime, s->prosek);
}

int main(int argc, char* argv[]){
  //Provera argumenata
  if(argc != 2)
    greska();
  
  //Otvaramo fajl za citanje
  FILE* ulaz = fopen(argv[1], "r");
  if(ulaz == NULL)
    greska();
  
  //Citamo dimenziju niza
  int n;
  fscanf(ulaz, "%d", &n);
  
  //Alociramo potrebnu memoriju
  STUDENT* niz;
  niz = malloc(n*sizeof(STUDENT));
  if(niz == NULL)
    greska();
  
  //Ucitavamo sve podatke u niz
  int i, ocena, j, suma;
  char tmp_prezime[MAX_IME];
  for(i=0; i<n; i++){
    //Nadovezivanje imena i prezimena u jednu nisku
    fscanf(ulaz, "%s %s", niz[i].puno_ime, tmp_prezime);
    strcat(niz[i].puno_ime, " ");
    strcat(niz[i].puno_ime, tmp_prezime);
    
    //Ucitavanje ocena i azuriranje broja ocena i proseka
    j=0, suma = 0;
    niz[i].broj_ocena = 0;
    while(1){
      fscanf(ulaz, "%d", &ocena);
      if(ocena == 0)
        break;
      
      niz[i].ocene[j++] = ocena;
      suma += ocena;
      niz[i].broj_ocena++;
    }
    niz[i].prosek = (float)suma/niz[i].broj_ocena;
  }
 
  //Ispis rezultata
  int p = najveci_prosek(niz, n);
  ispisi(&niz[p]);
 
  free(niz);
  fclose(ulaz);
  return 0;
}
