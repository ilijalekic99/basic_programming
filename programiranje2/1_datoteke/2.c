#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int main(){
	FILE* f = fopen("ulaz.txt","r");
	FILE* g = fopen("knjiga.txt","w");
	
	if(f == NULL)
		greska();
	
	char* line = NULL;
	size_t len = 0;
	
	int i = 0;
	
	while(getline(&line, &len, f) != -1)
		i++;
	
	printf("%d\n",i);
	
fclose(f);	
fclose(g);
return 0;
}
