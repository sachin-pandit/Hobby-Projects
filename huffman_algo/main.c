#include"header.h"

int main(int argc, char *argv[])
{
  tab *s;
  FILE *fp;
  indx *I, i, tab_size = 128, list_size = 128;
  dll *Head, *temp;
  int code;
  char **N;

  code = 1;

  N = (char **)calloc(tab_size, sizeof(char *));

  Head = mknode(-1, NULL, NULL, NULL, NULL);
  Head->next = Head;
  Head->prev = Head;

  fp = fopen(argv[1], "r");

  s = (tab *)freq_calc(fp);

  I = sort(s, tab_size);

  Head = tab_to_list(s, I, &list_size, Head);
  
  for(i = 0; i < tab_size; i++)
    printf("%3d '%c' %-lld\n", I[i], I[i], s[I[i]]);

  temp = Head->next;
  printf("\n");
  while(temp != Head){
    printf("%3d '%c' %-lld\n", temp->i, temp->i, s[temp->i]);
    temp = temp->next;
  }
  printf("\n");
  
  s = (tab *)realloc(s, (tab_size + list_size - 1)*sizeof(tab));

  Head = BuildTree(Head, s, &tab_size);

  printf("\ndigraph G{\n");
  traverse(s, Head->next, N, 1);
  printf("}\n");

  printf("\n\n");
  for(i = 0; i < tab_size; i++)
    printf("%3d '%c' %-lld\n", i, i, s[i]);
  printf("\n");

  fclose(fp);

  return 0;
}
