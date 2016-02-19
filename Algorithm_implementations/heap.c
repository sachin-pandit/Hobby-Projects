#include"header.h"
#define false 0
#define true 1
void bottomup(int *arr, int index , int size);
void heapify( int *arr, int size );
void swap(int *a, int *b);	

void main()
{
	int *arr, size, i, k = 0;
	
	system("clear");
	srandom(time(NULL));
	
	printf("Enter the size of an array : ");
	scanf("%d",&size);
	
	arr = (int *)calloc(size, sizeof(int));
	
	for( i = 0 ; i < size ; i++ )
		arr[i] = random()%10000;
		
	for( i = size ; i > 0 ; i-- ){
		heapify( arr, i );
		swap( &arr[1], &arr[i] );
	}
		
	for( i = 1 ; i < size ; i++ ){
		if( i%15 == 0 && i != 0 )
			printf("\n");
		printf("%7d",arr[i]);
	}
	printf("\n");
}

void heapify( int *arr, int size ){
	int i;
	for( i = size/2 ; i > 0 ; i-- )
		bottomup( arr, i , size);
}

void bottomup(int *arr, int index , int size){
	int i, value, flag;
	
	value = arr[index];
	flag = false;
	while( !flag && 2*index <= size ){
		i = 2*index;
		if( i < size )
			if( arr[i] < arr[i+1] )
				i++;
		if( value >= arr[i])
			flag = true;
		else{
			arr[index] = arr[i];
			index = i;
		}
	}
	arr[index] = value;
}

void swap(int *a, int *b){
	*a = *a - *b;
	*b = *b + *a;
	*a = *b - *a;
}
