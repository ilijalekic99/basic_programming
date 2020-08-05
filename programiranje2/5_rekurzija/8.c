#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

void obrni_niz(int *a, int n){
	if(n<=1)
		return;
	
	int tmp = *a;
	*a = a[n-1];
	a[n-1] = tmp;
	
	obrni_niz(a+1,n-2);
}

int main(){
	int n;
	scanf("%d",&n);
	
	int *a = malloc(n*sizeof(int));
	if(a == NULL)
		greska();
	
	for(int i = 0; i<n; i++)
		scanf("%d",&a[i]);
		
	obrni_niz(a,n);

	for(int i = 0; i<n; i++)
		printf("%d ",a[i]);
	
	
free(a);
return 0;
}
