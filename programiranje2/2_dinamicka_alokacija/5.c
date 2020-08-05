#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_REC 21

void greska()
{
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main(){
  char* uneta, *rec;
  uneta = malloc(MAX_REC*sizeof(char));
  if(uneta == NULL)
    greska();
  
  rec = malloc(MAX_REC*sizeof(char));
  if(rec == NULL)
    greska();
  
  int prva = -1, poslednja = -1;
  int n, i;
  
  scanf("%s%d", uneta, &n);
  
  if(n <= 0)
    greska();
  
  for(i=0; i<n; i++)
  {
    scanf("%s", rec);
    if(strcmp(uneta, rec) == 0)
    {
        if(prva == -1)
          prva = i;
        poslednja = i;
    }
  }
  printf("%d %d\n", prva, poslednja);
  
  free(uneta);
  free(rec);
  return 0;
}
