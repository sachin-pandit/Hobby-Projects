#include"header.h"

dll *BuildTree(dll *Head, tab *T, indx *size)
{
  dll *derived;
  dll *child1, *child2;
  indx new;

  if(Head->next == Head->prev)
    return (Head);

  delete_last(Head, &child1);
  delete_last(Head, &child2);

  new = T[child1->i] + T[child2->i];

  derived = mknode((*size)++, NULL, NULL, child1, child2);

  T[(*size)-1] = new;

  Head = order_insert(T, Head, derived);

  return ( BuildTree(Head, T, size) );
}
