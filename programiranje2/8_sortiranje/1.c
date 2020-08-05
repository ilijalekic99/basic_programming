#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

void selection_sort(int *niz, int n){
	for(int i = 0; i<n; i++){
		int min = i;
		for(int j = i; j<n; j++){
			if(niz[j] < niz[min])
				min = j;
		}
		int tmp = niz[min];
		niz[min] = niz[i];
		niz[i] = tmp;
	}
}

void insertion_sort(int *niz, int n){
	for(int i = 1; i<n; i++){
		int j;
		int trenutni = niz[i];
		for(j = i; j>0 && trenutni < niz[j-1]; j--){
			niz[j] = niz[j-1];
		}
		niz[j] = trenutni;
	}
}

void merge(int *a, int n, int* b, int m, int *c){
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < n && j < m){
		if(a[i] < b[j]){
			c[k] = a[i];
			k++;
			i++;
		} else {
			c[k] = b[j];
			k++;
			j++;
		}
	}
	while(i < n){
		c[k] = a[i];
		k++;
		i++;
	}
	while(j < m){
		c[k] = b[j];
		k++;
		j++;
	}
}


void merge_sort(int *niz, int l, int d, int *pom){
	if(l >= d)
		return;
	
	int n = d - l + 1;
	int s = l + n/2;
	
	merge_sort(niz,l,s-1,pom);
	merge_sort(niz,s,d,pom);
	
	int n1 = s - l;
	int n2 = n - n1;
	
	merge(niz + l, n1, niz + s, n2, pom);	
	
	int i,j;
	for(i = l, j = 0; i <= d; i++, j++){
		niz[i] = pom[j];
	}
}

int particionisi(int *niz, int l, int d){
	int pivot = niz[l];
	while(l < d){
		while(niz[d] >= pivot && l < d){
			d--;
		}
		if(l != d){
			niz[l++] = niz[d];
		}
		while(niz[l] <= pivot && l < d){
			l++;
		}
		if(l != d){
			niz[d--] = niz[l];
		}
	}
	niz[l] = pivot;
	return l;	
}

void quick_sort(int *niz, int l, int d){
	if(l >= d)
		return;
	
	int poz_pivot = particionisi(niz,l,d);
	
	quick_sort(niz,l,poz_pivot - 1);
	quick_sort(niz,poz_pivot + 1, d);
}


int main(){
	int n;
	scanf("%d",&n);
	
	int *niz = malloc(n*sizeof(int));
	if(niz == NULL)
		greska();
	
	for(int i = 0; i<n; i++)
		scanf("%d",&niz[i]);
	
	
	selection_sort(niz,n);
	insertion_sort(niz,n);
	
	int *pom = malloc(n*sizeof(int));
	if(pom == NULL)
		greska();
	merge_sort(niz,0,n-1,pom);
	quick_sort(niz,0,n-1);
	
	for(int i = 0; i<n; i++)
		printf("%d",niz[i]);

return 0;
}
