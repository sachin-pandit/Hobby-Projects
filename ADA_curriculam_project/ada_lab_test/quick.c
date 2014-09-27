#include"header.h"
int partition( int *arr, int low, int high );
void swap(int *a,int *b);
void quick(int *arr, int low, int high);

void main()
{
	int *arr, size, i;
	
	system("clear");
	
	srandom(time(NULL));
	
	printf("Enter the size of an array : ");
	scanf("%d",&size);
	
	arr = (int *)calloc(size,sizeof(int));
	
	for( i = 0 ; i < size ; i++ )
		arr[i] = random()%100000;
		
	quick( arr, 0, size-1 );
	
	for( i = 0 ; i < size ; i++ ){
		if( i%15==0 && i != 0 )
			printf("\n");
		printf("%7d",arr[i]);
	}
	printf("\n");
}

void quick(int *arr, int low, int high){
	int split;
	if( low < high ){
		split = partition( arr, low, high );
		quick( arr, low, split-1 );
		quick( arr, split+1, high );
	}
}

int partition( int *arr, int low, int high ){
	int pivot , i , j;
	
	pivot = arr[low];
	i = low;
	j = high+1;
	do{
		while(arr[++i] < pivot );
		while(arr[--j] > pivot );
		swap( &arr[i], &arr[j]);
	}while(i<j);
	swap( &arr[i], &arr[j]);
	swap( &arr[low], &arr[j]);
	return j;
}

void swap( int *a, int *b){
	int temp;
	temp = *a;
	*a   = *b;
	*b   = temp;
}
	
