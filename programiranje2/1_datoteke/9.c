#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int main(int argc, char** argv){
	
	char* s;
	
	int i = 0;
	while(argv[i]){
	
		s = argv[i];
		
		if(s[0] == '-'){
			for(int j = 1; j<strlen(s); j++)
				printf("%c ",s[j]);
		
		}
	
		i++;
	}

return 0;
}
