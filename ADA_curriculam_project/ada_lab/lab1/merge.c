#include<stdio.h>
#define MAX_ARRAY_SIZE 20
main()
{
	int numbers[ MAX_ARRAY_SIZE ], i, array_size = 0, child1_size, child2_size; 
	srandom ( time(NULL) );
	for ( i = 0; i < MAX_ARRAY_SIZE; i++, array_size++ )
		numbers[i] = (int)random() % 20000;
	child2_size = ( array_size % 2 ) ? ( array_size / 2 + 1 ) : ( array_size / 2 );
	child1_size = ( array_size / 2 );
	mergesort( numbers, array_size, child1_size, child2_size );
	for ( i = 0; i < array_size; i++ )
		printf("<%5d>  %7d\n", i + 1, numbers[i] );
}
mergesort(int array, int array_size, int child1_size, int child2_size )
{
	int first_half[ child1_size ], second_half[ child2_size ], i, kid1_size, kid2_size;
	if( array_size > 1 ){
		for ( i = 0; i < MAX_ARRAY_SIZE / 2; i++ )
			first_half[i] = array[i];
		for ( i = MAX_ARRAY_SIZE / 2; i < MAX_ARRAY_SIZE; i++ )
			second_half[i] = array[i];
		kid2_size = ( child2_size % 2 ) ? ( child2_size / 2 + 1 ) : ( child2_size / 2 );
		kid1_size = ( child1_size / 2 );
		mergesort( first_half, child1_size, kid1_size, kid2_size );
		mergesort( second_half, child2_size, kid1_size, kid2_size );
		merge( first_half, second_half, child1_size, child2_size, array );
		}
}

merge( int child1, int child2, int child1_size, int child2_size, int array )
{
	int i, j, k;
	i = j = k = 0;
	while ( i < child1_size && j < child2_size ){
		if ( child1[i] <= child2[j] ){
			array[k] =  child1[i];
			i++ ;
		}
		else{
			array[k] = child2[j];
			j++ ;
		}
		k++ ;
	}
	if ( i == child1_size )
		for ( ; j < child2_size; j++, k++ )
			array[k] = child2[j];
	else
		for ( ; i < child1_size; i++, k++ )
			array[k] = child1[i];
}
	
	
	
	
	
	
	
	
	
	
	
	

