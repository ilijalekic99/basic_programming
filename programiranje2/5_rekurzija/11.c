#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int skalarni_proizvod(int* a, int* b, int n){
  if(n == 0)
    return 0;
	
  return a[0] * b[0] + skalarni_proizvod(a+1, b+1, n-1);
}

int main(){
	int n;
	scanf("%d",&n);
	
	int *a = malloc(n*sizeof(int));
	int *b = malloc(n*sizeof(int));
	
	for(int i = 0; i<n; i++)
		scanf("%d",&a[i]);

	for(int i = 0; i<n; i++)
		scanf("%d",&b[i]);
	
	printf("%d\n",skalarni_proizvod(a,b,n));

free(a);
free(b);
return 0;
}
