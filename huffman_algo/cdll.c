#include"header.h"

dll *mknode(indx i, dll *prev, dll *next, dll *c1, dll *c2)
{
  dll *node;

  node = (dll *)malloc(sizeof(dll));
  node->i = i;
  node->next = next;
  node->prev = prev;
  node->lchild = c1;
  node->rchild = c2;

  return (node);
}

dll *order_insert(tab *T, dll *head, dll *node)
{
  dll *temp;

  temp = head->next;
  while(temp != head && T[temp->i] > T[node->i])
    temp = temp->next;

  temp->prev->next = node;
  node->prev = temp->prev;
  node->next = temp;
  temp->prev = node;

  return (head);
}

dll *delete_last(dll *head, dll **dustbin)
{
  dll *temp;

  temp = head->prev;
  if(temp == head){
    *dustbin = NULL;
    return (head);
  }

  head->prev = temp->prev;
  temp->prev->next = head;
  temp->prev = temp->next = NULL;

  *dustbin = temp;

  return (head);
}
