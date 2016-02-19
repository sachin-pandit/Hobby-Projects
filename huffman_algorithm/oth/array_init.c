#include<stdio.h>
#include<stdlib.h>

int main()
{
  int *arr, i;
  arr = (int *)calloc(10, sizeof(int));

  for(i = 0; i < 10; i++)
    printf("%d\n", arr[i]);

  return 0;
}
