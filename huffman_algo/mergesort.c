#include"header.h"

void Merge(tab *A, indx *B, indx *C, indx *I, indx b, indx c)
{
  indx i, j, k;

  i = j = k = 0;

  while(i < b && j < c){
    if(A[B[i]] > A[C[j]])
      I[k++] = B[i++];
    else
      I[k++] = C[j++];
  }

  if(i == b)
    while(j < c)
      I[k++] = C[j++];
  else
    while(i < b)
      I[k++] = B[i++];
}

void MergeSort(indx *I, tab *A, indx size)
{
  indx *B, *C, b = size/2, c = size - b, i, j;

  if(size <= 1)
    return;

  B = (indx *)calloc(b, sizeof(indx));
  C = (indx *)calloc(c, sizeof(indx));

  for(i = 0; i < b; i++)
    B[i] = I[i];

  for(j = 0; j < c; j++, i++)
    C[j] = I[i];

  MergeSort(B, A, b);
  MergeSort(C, A, c);

  Merge(A, B, C, I, b, c);
}

indx *sort(tab *arr, int size)
{
  indx *I;
  int i;

  I = (indx *)calloc(size, sizeof(indx));

  for(i = 0; i < size; i++)
    I[i] = i;

  MergeSort(I, arr, size);

  return (I);
}
