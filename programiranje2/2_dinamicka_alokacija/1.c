#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int main(){
	int n;
	scanf("%d",&n);
	
	int *a = malloc(n*sizeof(int));
	
	for(int i = 0; i<n; i++)
		scanf("%d",&a[i]);
		
	while(n>0){
		printf("%d ",a[n-1]);
		n--;
	}

return 0;
}
