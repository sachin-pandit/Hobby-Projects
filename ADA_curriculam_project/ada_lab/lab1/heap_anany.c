#include<stdio.h>
#include<stdlib.h>



void main()
{
	int *heap, size = 1000, i;
	
	heap = (int *)calloc(size, sizeof(int));
	for( i = 0 ; i < size ; i++ )
		heap[i] = random()%10000;
	
	for( i = size-1 ; i > = 0  ; i-- ){
		build_max_heap(heap, i);
		swap( heap[0], heap[i] );
	}
	
	for( i = 0 ; i < size ; i++ ){
		printf("%8d",heap[i]);
		if( i % 15 == 0 && i != 0 )
			printf("\n");
	}
}


void build_max_heap(int *heap, int size){
	
