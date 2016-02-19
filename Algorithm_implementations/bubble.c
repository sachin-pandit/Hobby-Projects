#include"header.h"

void swap( int *a, int *b);

void main()
{
	int *arr, size , i , j;
	
	srandom(time(NULL));
	
	system("clear");
	
	printf("Enter the size of array : ");
	scanf("%d",&size);
	
	arr = (int *)malloc(sizeof(int));
	
	for( i = 0 ; i < size ; i++ )
		arr[i] = random()%1000;
	
	for( i = 0 ; i < size ; i++ ){
		for( j = 0 ; j < size-1 ; j++ ){
			if( arr[j] > arr[j+1] )
				swap( &arr[j], &arr[j+1] );
		}
	}
	
	for( i = 0 ; i < size ; i++ ){
		if( i%15==0 && i != 0 )
			printf("\n");
		printf("%7d", arr[i] );
	}
	printf("\n");
}

void swap( int *a, int *b){
	*a = *a - *b;
	*b = *a + *b;
	*a = *b - *a;
}
	
	
