#include<stdio.h>
#include<stdlib.h>

void greska()
{
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]){

  if(argc != 2)
    greska();
  
  int i, n, alocirano;
  int *a;
  
  
  int k = atoi(argv[1]);
  if(k <= 0)
    greska();
  
   
  a = (int*)malloc(k*sizeof(int));
  if(a == NULL)
    greska();
  
  alocirano = k;
  
  FILE* ulaz = fopen("brojevi.txt", "r");
  if(ulaz == NULL)
    greska();
  
  i = 0;
  while(1){
    
    if(i == alocirano){
        a = realloc(a, alocirano*sizeof(int));
        if(a == NULL)
          greska();
    }
    fscanf(ulaz, "%d", &a[i]);
    if(a[i] == 0)
      break;
    i++;
  }

  n = i;  
  
  float srednji;
  if(n%2 == 0)
    srednji = (a[n/2-1] + a[n/2])/2.0;
  else
    srednji = a[n/2];
  
  
  for(i=0; i<n; i++)
    if(a[i] > srednji)
      printf("%d ", a[i]);
  printf("\n");
  
  
  free(a);
  
  fclose(ulaz);
  return 0;

}
