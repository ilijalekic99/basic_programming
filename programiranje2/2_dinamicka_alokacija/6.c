#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

typedef struct{
	unsigned int a, b;
	char ime[5];
} PRAVOUGAONIK;

int main(int argc, char** argv){
	
	if(argc != 2)
		greska();
	
	FILE *f = fopen(argv[1],"r");
	if(f == NULL)
		greska();
	
	PRAVOUGAONIK pr;
	
	unsigned max = 0;
	
	while(fscanf(f,"%u %u %s",&pr.a, &pr.b, pr.ime) != EOF){
		if(pr.a == pr.b)
			printf("%s ",pr.ime);
		
		if((pr.a * pr.b) > max)
			max = (pr.a * pr.b);
	}	
		printf("%u\n",max);

return 0;
}
