#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

void linearno(int n, int *a, int x){
	for(int i = 0; i<n; i++){
		if(a[i] == x){
			printf("%d\n",i);
			break;
		}
	}
}

int binarna_pret(int *a, int n, int x){
	int l = 0;
	int d = n-1;
	int s;	
	
	while(l <= d){
		s = l + (d-l)/2;
		if(a[s] == x)
			return s;
		else if(x < a[s])
			d = s - 1;
		else 
			l = s + 1;
	}
	return -1;
}

int bin_pret_rek(int *a, int l, int d, int x){
	if(l > d)
		return -1;
	
	int s = l + (d-l)/2;
	if(x == a[s])
		return s;
	else if(x < a[s])
		return bin_pret_rek(a,l,s-1,x);
	else 
		return bin_pret_rek(a,s+1,d,x);
}

int poredi(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int main(){
	int n;
	scanf("%d",&n);
	
	int *a = malloc(n*sizeof(int));
	if(a == NULL)
		greska();
	
	for(int i = 0; i<n; i++)
		scanf("%d",&a[i]);
	
	int x;
	scanf("%d",&x);
		
	printf("LINEARNA:");
	linearno(n,a,x);
	
	printf("BINARNA: %d\n", binarna_pret(a,n,x));
	printf("BINARNA REKURZIVNO: %d\n", bin_pret_rek(a,0,n-1,x));
			
	int *p = bsearch(&x,a,n,sizeof(int),&poredi);
	if(p == NULL)
		printf("bsearch: -1\n");
	else printf("bsearch: %ld\n",p-a);
			
free(a);
return 0;
}
