#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr,"-1");
	exit(EXIT_FAILURE);
}

int provera_razlomka(char* razlomak){
  int i, crte = 0;
  
  for(i=0; razlomak[i]; i++)
  {
    if(!isdigit(razlomak[i]) && razlomak[i] != '/')
      return 0;
    
    if(razlomak[i] == '/')
      crte++;
  }
  
   if(razlomak[0] == '/' || razlomak[i-1] == '/' || crte != 1)
    return 0;

  
  return 1;
}

int main(int argc, char** argv){
  int i, brojilac, imenilac;
  
  
  for(i=1; i<argc; i++)
  {
    if(!provera_razlomka(argv[i]))
      greska();
  }
  
  for(i=1; i<argc; i++){
    sscanf(argv[i], "%d/%d", &brojilac, &imenilac);
    printf("%.2f ", (float)brojilac/imenilac);
  }
  printf("\n");
	

return 0;
}
