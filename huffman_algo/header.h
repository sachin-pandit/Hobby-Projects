#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned long long int tab;
typedef unsigned short int indx;
typedef struct llnode dll;

struct llnode
{
  indx i;
  struct llnode *next, *prev;
  struct llnode *lchild, *rchild;
};

tab *freq_calc(FILE *);
indx *sort(tab *, int);
dll *tab_to_list(tab *, indx *, indx *, dll *);
dll *mknode(indx, dll *, dll *, dll *, dll *);
dll *order_insert(tab *, dll *, dll *);
dll *delete_last(dll *, dll **);
dll *BuildTree(dll *, tab *, indx *);
void traverse(tab *, dll *, char **, int);
char *atob(int);
