#include<stdio.h>
#include<time.h>

typedef int index;

int heap_size, length;

index parent(index i)
{
  return (i/2);
}

index left(index i)
{
  return (2*(i+1) - 1);
}

index right(index i)
{
  return (2*(i+1));
}

void swap(int *a, index i, index j)
{
  int temp;
  
  temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

void MaxHeapify(int *a, index i)
{
  index l, r, largest;
  
  l = left(i);
  r = right(i);
  
  if(l <= heap_size && a[l] > a[i])
    largest = l;
  else
    largest = i;
  
  if(r <= heap_size && a[r] > a[largest])
    largest = r;

  if(largest != i){
    swap(a, i, largest);
    MaxHeapify(a, largest);
  }
}

void BuildMaxHeap(int *a)
{
  index i;

  heap_size = length - 1;
  for(i = length/2 - 1; i >= 0 ; i--)
    MaxHeapify(a, i);
}

void Heapsort(int *a)
{
  index i;

  BuildMaxHeap(a);
  for(i = length - 1; i >= 1; i--){
    swap(a, 0, i);
    heap_size--;
    MaxHeapify(a, 0);
  }
}

index check(int *a)
{
  index i;
  for(i = 0; i < length-1; i++)
    if(a[i] > a[i+1])
      return (i);

  return(i);
}

main()
{
  index i, size, max = 100, slab = 100;
  int a[max];
  clock_t t1, t2;
  float t;
  
  srandom(time(NULL));
  
  for(size = slab; size < max + slab; size += slab){
    length = size;

    for(i = 0; i < length; i++)
      a[i] = (int)random();
      //scanf("%d", &a[i]);
    
    printf("Priori Heapsort:\n");
    for(i = 0; i < length; i++)
      printf("%10d, ", a[i]);
    t1 = clock();
    Heapsort(a);
    t2 = clock();
    
    printf("\nAfter Heapsort:\n");
    for(i = 0; i < length; i++)
      printf("%10d, ", a[i]);
 
    i = check(a);
    if(i != length - 1)
      printf("error at %d\n", i);
   
    t = ((double)(t2 - t1))/CLOCKS_PER_SEC;
    
    printf("%d %g\n", size, t);
  }
}
  
