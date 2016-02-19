#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void build_max_heap(int *heap, int length, int size);
void max_heapify(int *heap, int index, int size);
void swap(int *,int, int);


void main()
{
	int *heap, *sort, i, length = 30, size;
	
	system("clear");	
	
	heap = (int *)calloc(length,sizeof(int));
	sort = (int *)calloc(length, sizeof(int));
	
	for( i = 1 ; i <= length ; i++ )
		heap[i] = random()%10000;
		
	size = length;
	printf("\nIn main\n");
	
	build_max_heap( heap, length, size);
	for( i = length ; i >= 1 ; i-- ){
		swap( heap, 1, i);
		sort[i] = heap[1];
		size--;
		max_heapify(heap, 1, size);
	}
	
	printf("The heap is\n");
	for( i = length ; i >= 1 ; i-- ){
		printf("%8d",heap[i]);
		if( i % 15 == 0 && i != 0 )
			printf("\n");
	}
	printf("------------------------\n");
	printf("The sorted array is\n");
	for( i = length ; i >= 1 ; i-- ){
		printf("%8d",sort[i]);
		if( i % 15 == 0 && i != 0 )
			printf("\n");
	}
	printf("\n");
}


void build_max_heap(int *heap, int length, int size){
	int i;
		printf("\nIn build max heap\n");

	size = length;
	for( i = length/2 ; i > 0 ; i-- )
		max_heapify(heap, i, size);
}

void max_heapify(int *heap, int index, int size){
	int left, right, largest, i;
		printf("\nIn max heapify\n");

	left = 2*(index+1)-1;
	right = 2*(index + 1);
	if( left <= size && heap[left] > heap[right] )
		largest = left;
	else
		largest = index;
	if( right <= size && heap[right] > heap[largest] )
		largest = right;
	if( largest != index ){
		swap( heap, i, largest );
		max_heapify( heap, largest, size);
	}
}
	
void swap(int *a, int i, int j){
	int temp;
		printf("\nIn swap\n");

	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
