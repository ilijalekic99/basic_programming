#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int main(int argc, char** argv){
	
	int n = argc;
	printf("1. ./a.out\n");
	
	int j = 1;
	for(int i = 2; i<=n; i++){
		printf("%d. %s\n", i,argv[j]);
		
		j++;
	}
	

return 0;
}
