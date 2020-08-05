#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

void f1(int *a, int n, int x){
	if(n <= 1)
		return;
	
	int a0,a1;
	a0 = a[0];
	a1 = a[1];
	
	f1(a+1,n-1,x);
	
	if(a0 + a1 == x){
		a[0] = 0;
		a[1] = 0;
	}
}

int main(){
	int n,x;
	
	scanf("%d%d",&x,&n);
	
	int *a = malloc(n*sizeof(int));
	if(a == NULL)
		greska();
	
	for(int i = 0; i<n; i++)
		scanf("%d",&a[i]);
	
	f1(a,n,x);
	for(int i = 0; i<n; i++)
		printf("%d ",a[i]);
	
	
	
free(a);
return 0;
}
