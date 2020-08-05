#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int main(int argc, char** argv){
	
	if(argc != 2)
		greska();
	
	FILE *f = fopen(argv[1],"r");
	if(f == NULL)
		greska();
		
	char rec[21];
	int br,duzina,cnt = 0;
	
	scanf("%d %s",&br,rec);
	
	duzina = strlen(rec);
	
	char* line = NULL;
	size_t len = 0;
	
	while(getline(&line,&len,f) != -1){
		int n = strlen(line);
		char* pom  = malloc(duzina*sizeof(char));
		
		for(int i = 0; i<n; i+=(duzina+1)){
			for(int j = 0; j<duzina; j++){
				pom[j] = line[j];
			}
			
			if(strcmp(pom,rec))
				cnt++;
		}	
	
		cnt = 0;	
	
		if(cnt > br)
			printf("%s\n",line);
		free(pom);
	}
	
fclose(f);
return 0;
}
