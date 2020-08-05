#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int main(){
	
	int n;
	scanf("%d",&n);
	
	if(n <= 0 || n > 100)
		greska();
	
	FILE *f;
	char ime_fajla[51];
	
	for(int i = 1; i<=n; i++){
		sprintf(ime_fajla, "%d.txt",i);
		
		f = fopen(ime_fajla,"w");
		if(f == NULL)
			greska();
		
		for(int j = 0; j<=n; j+=i){
			fprintf(f,"%d ",j);
		}
		fprintf(f,"\n");
		fclose(f);
	}	

return 0;
}
