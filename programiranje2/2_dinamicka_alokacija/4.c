#include<stdio.h>
#include<stdlib.h>

void greska()
{
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int** alociraj(int n, int m){
  int i;
  int ** A = malloc(n*sizeof(int*));
  if(A == NULL)
    greska();
  
  for(i=0; i<n; i++)
  {
    A[i] = malloc(m*sizeof(int));
    if(A[i] == NULL)
      greska();
  }
  return A;
}

int sum_max(int **A, int n, int m){
  int i, j, sum = 0;
  for(i=0; i<n; i++){
    int max = A[i][0];
    for(j=1; j<m; j++){
      if(A[i][j] > max)
        max = A[i][j];
    }
    sum += max;
  }
  return sum;
}

int main(){

  int i, j, n, m;
  int **A;

  
  scanf("%d%d", &n, &m);
  if(n <= 0 || m <= 0)
    greska();
  
  A = malloc(n*sizeof(int*));
  if(A == NULL)
    greska();
  
  for(i=0; i<n; i++)
  {
    A[i] = malloc(m*sizeof(int));
    if(A[i] == NULL)
      greska();
  }

  for(i=0; i<n; i++)
    for(j = 0; j<m; j++)
      scanf("%d", &A[i][j]);
  

    for(i=0; i<n; i++){
      for(j = 0; j<m; j++)
        printf("%d ", A[i][j]);  
      printf("\n");
    }
    
    printf("%d\n", sum_max(A, n, m));
  
 
  for(i=0; i<n; i++)
    free(A[i]);
  free(A);
  
  return 0;

}
