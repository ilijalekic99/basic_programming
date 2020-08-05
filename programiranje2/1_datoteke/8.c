#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int main(int argc, char** argv){
	
	if(argc != 3)
		greska();
	
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	
	if(a > b)
		greska();
	
	while(a <= b){
		printf("%d ",a);
		a++;
	}

return 0;
}
