#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  
  srand(time(NULL));
  printf("%.2lf\n", (double)rand()/RAND_MAX);
  
  return 0;
}
