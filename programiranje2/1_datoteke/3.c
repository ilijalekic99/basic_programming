#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void greska(){
	fprintf(stderr,"-1\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char** argv){
	
	if(argc != 4)
		greska();
	
	char* c = argv[3];
	
	FILE* f = fopen(argv[1],"r");
	FILE* g = fopen(argv[2],"w");
	
	if(f == NULL)
		greska();
	
	
	if(c[0] != 'l' && c[0] != 'u')
		greska();
	
	char k,rez;
	
	while(fscanf(f,"%c",&k) != EOF){
		if(c[0] == 'l')
			rez = toupper(k);
		else
			rez = tolower(k);
		
		printf("%c",rez);
	}
	
fclose(f);
fclose(g);
return 0;
}
