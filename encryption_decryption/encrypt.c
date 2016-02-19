#include<stdio.h>
#include<stdio.h>

#define BIN_LEN 4

char *get_ascii(char *str, int *out_len)
{
  int ascii, i=0, *out_str, j=0;

  out_str = (int *)calloc(j+1, sizeof(int));
  while(str[i] != EOF){
    out_str = (int *)realloc(out_str, (j+3)*sizeof(int));
    ascii = str[i++];
    out_str[j++] = (ascii/100)%10;
    out_str[j++] = (ascii/10)%10;
    out_str[j++] = ascii%10;
  }

  *out_len = j+1;
  return(out_str);
}

int *encrypt(int *str, int in_len, int *out_len)
{
  int bin, i=0, *out_str, j=0, binlen;

  out_str = (int *)calloc(j+1, sizeof(int));
  while(i < in_len){
    out_str = (int *)realloc(out_str, (j+BIN_LEN)*sizeof(int));
    binlen = 0;
    
    while(binlen < BINLEN){
      out_str[j++] = 
}

main()
{
  char *text, c;
  int i=0, tlen, *ascii, alen, *enc, elen;

  text = (char *)calloc(i+1, sizeof(char));
  while((c = getchar()) != EOF){
    text = (char *)realloc(text, (i+1)*sizeof(char));
    text[i++] = c;
  }
  text[i] = 0;
  len = i;

  ascii = get_ascii(text, &alen);

  enc = encrypt(ascii, alen, &elen);

  print(enc, elen);
}
 
