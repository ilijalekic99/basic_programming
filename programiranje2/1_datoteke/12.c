#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]){
  if(argc != 4)
    error();
  
  int n, a, b;
  n = atoi(argv[1]);
  a = atoi(argv[2]);
  b = atoi(argv[3]);
  
  if(n > 200 || a >= b)
    error();
  
  srand(time(NULL));
  
  int i;
  for(i=0; i<n; i++)
    printf("%d ", (int)(a + (b-a)*((float)rand()/RAND_MAX)));
  
  return 0;
}
