#include"header.h"

tab *freq_calc(FILE *fp)
{
  tab *symbols;
  char c;

  symbols = (tab *)calloc(128, sizeof(tab));
  
  while((c = getc(fp)) != EOF){
    if(c <= 127 && c >= 0)
      symbols[(int)c]++;
  }

  return (symbols);
}
