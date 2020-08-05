#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int pal(int* a,int n){
	if(n <= 1)
		return 1;
	
	if(*a != a[n-1])
		return 0;
	
	return pal(a+1,n-2);

}

int main(){
	int n;
	scanf("%d",&n);
	
	int *a = malloc(n*sizeof(int));
	if(a == NULL)
		greska();
	
	for(int i = 0; i<n; i++)
		scanf("%d",&a[i]);
	
	if(pal(a,n) == 1)
		printf("DA\n");
	else printf("NE\n");
	
free(a);
return 0;
}
