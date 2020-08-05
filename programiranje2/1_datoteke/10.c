#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int main(int argc , char** argv){
	
	if(argc != 3)
		greska();
	
	FILE *f = fopen(argv[1],"r");
	if(f == NULL)
		greska();
	
	FILE *g = fopen(argv[2],"r");
	if(g == NULL)
		greska();
	
	char *line1 = NULL;
	size_t len1 = 0;
	char *line2 = NULL;
	size_t len2 = 0;
	
	int i = 1;
	while(getline(&line1,&len1,f) != -1 && getline(&line2,&len2,g) != -1){
		if(strcmp(line1,line2) != 0)
			printf("%d ",i);
		i++;
	}
	

fclose(f);
fclose(g);	
return 0;
}
