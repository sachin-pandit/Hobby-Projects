#include"header.h"

dll *tab_to_list(tab *T, indx *I, indx *size, dll *Head)
{
  dll *new, *cur;
  indx i;

  cur = Head;
  for(i = 0; i < *size && T[I[i]]; i++){
    new = mknode(I[i], cur, Head, NULL, NULL);

    cur->next = new;
    new->prev = cur;
    Head->prev = new;
    new->next = Head;

    cur = new;
  }

  *size = i;

  return (Head);
}

void traverse(tab *T, dll *node, char **NameTab, int name)
{
  indx c;
  char *s;

  if(node->lchild != NULL){
    printf("%d [label=\"%lld\"];\n", node->i, T[node->i]);
    printf("%d -> %d [label = \"0\"];\n", node->i, node->lchild->i);
    name *= 2;
    traverse(T, node->lchild, NameTab, name);
    name /= 2;

    if(node->rchild != NULL){
      printf("%d -> %d [label = \"1\"];\n", node->i, node->rchild->i);
      name *= 2;
      name += 1;
      traverse(T, node->rchild, NameTab, name);
      name /= 2;
    }

  }
  else{
    c = node->i;
    s = atob(name);
    NameTab[c] = (char *)calloc(strlen(s)+1, sizeof(char));
    strcpy(NameTab[c], s);
    if(
       c == '"'
       ||
       c == '\\'
       )
      printf("%d [label=\"'\\%c'(%s)\"];\n", c, c, s);
    else if(c == '\n')
      printf("%d [label=\"'\\n'(%s)\"];\n", c, s);
    else if(c == '\t')
      printf("%d [label=\"'\\t'(%s)\"];\n", c, s);
    else
      printf("%d [label=\"'%c'(%s)\"];\n", c, c, s);
  }

  return;
}

char *atob(int n)
{
  char *s, c;
  int i, j;

  s = (char *)calloc(1, sizeof(char));
  i = 0;
  while(n){
    s = (char *)realloc(s, (i+1)*sizeof(char));
    s[i++] = (n % 2) + '0';
    n >>= 1;
  }
  i--;
  s[i] = 0;

  j = 0;
  while(i-1 > j){
    c = s[j];
    s[j++] = s[i-1];
    s[i-- -1] = c;
  }

  return (s);
}
