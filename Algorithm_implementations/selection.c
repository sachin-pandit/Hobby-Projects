#include"header.h"
void swap(int *a, int *b);


void main()
{
	int *arr, size, i , j;
	
	system("clear");
	
	srandom(time(NULL));
	
	printf("Enter the size of an array : ");
	scanf("%d",&size);
	
	arr = (int *)malloc(sizeof(int));
	
	for( i = 0 ; i < size ; i++ )
		arr[i] = random()%10000;
		
	for( i = 0 ; i < size-1 ; i++ ){
		for( j = i+1 ; j < size ; j++ ){
			 if( arr[i] > arr[j])
			 	swap( &arr[i] , &arr[j] );
		}
	}
	
	for( i = 0 ; i < size ; i++ ){
		if( i % 15 == 0 && i != 0 )
			printf("\n");
		printf("%7d",arr[i]);
	}
	printf("\n");
}

void swap(int *a, int *b){
	*a = *a - *b;
	*b = *a + *b;
	*a = *b - *a;
}

		
