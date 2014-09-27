#include"header.h"

void merge(int *arr, int size, int *left, int left_size, int *right, int right_size );
void merge_sort(int *arr, int size);
void binary( int *, int  , int , int  );
int flag;

void main()
{
	int *arr, size, i , key;
	
	system("clear");
	
	srandom(time(NULL));
	
	printf("Enter the size of an array : ");
	scanf("%d",&size);
	
	arr = (int *)calloc(size+1,sizeof(int));
	
	for( i = 0 ; i < size ; i++ )
		arr[i] = random()%1000;
		
	merge_sort( arr, size);
	
	for( i = 0 ; i < size ; i++ ){
		if( i%15==0 && i!=0 )
			printf("\n");
		printf("%7d",arr[i]);
	}
	printf("\n");
	sleep(1);
	key = random()%1000 ;
	printf("The key selected is : %d\n",key);
	
	binary( arr, 0 , size-1 , key );
	if( flag == 0 )
		printf("Key not found\n");
}

void binary( int *arr, int low, int high, int key ){
	int mid;
	if( low <= high ){
		mid = (low + high)/2; 
		if( arr[mid] == key ){		
			flag = 1;
			printf("Key found at %d position\n", mid+1);
		}
		else if( arr[mid] > key )
			binary( arr, low, mid-1 , key );
		else if( arr[mid] < key )
			binary( arr, mid+1 , high , key );
	}
}		

void merge_sort(int *arr, int size){
	int *left, *right, i, j;
	left = (int *)calloc(size/2+1, sizeof(int));
	right = (int *)calloc(size/2+1, sizeof(int));
	if( size > 1 ){
		for( i = 0 ; i < size/2 ; i++ )
			left[i] = arr[i];
		
		for( j = 0 ; i < size ; j++ )
			right[j] = arr[i++];
			
		merge_sort( left, i-j );
		merge_sort( right, j );
		
		merge( arr, i, left, i-j, right, j );
	}
}

void merge(int *arr, int size, int *left, int left_size, int *right, int right_size ){
	int i = 0 , j = 0 , k = 0;
	while( i < left_size && j < right_size ){
		if( left[i] < right[j] )
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	if( i == left_size ){
		while( j < right_size )
			arr[k++] = right[j++] ;
	}
	
	else{
		while( i < left_size )
			arr[k++] = left[i++];
	}
} 
	
	
