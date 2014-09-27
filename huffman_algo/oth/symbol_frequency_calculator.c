#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
  unsigned long long int symbols[127] = {0};
  char c;
  FILE *fp;
  int i, total;

  if(argc < 2)
    return 0;
  
  i = 1;
  while(i <= argc){
    fp = fopen(argv[i], "r");

    total = 0;
    while((c = getc(fp)) != EOF){
      symbols[(int)c]++;
      total++;
    }

    printf("\nFile: %s\n", argv[i]);
    printf("| INDEX | SYMBOL | OCCURENCE | FREQUENCY\n");
    printf("| %5d |  '\\n'  | %9lld | %.10f\n", 10, symbols[10], (symbols[10]*1.0)/total);
    for(i = 32; i < 127; i++)
      printf("| %5d |   '%c'  | %9lld | %.10f\n", i, i, symbols[i], (symbols[i]*1.0)/total);

    fclose(fp);
  }
  
  return 0;
}
