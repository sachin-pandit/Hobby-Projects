#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge_them( int *first, int first_i, int *sec, int sec_i, int *mer, int size){
	int i = 0, j = 0, k = 0;
	while( i < first_i && j < sec_i ){
		if( first[i] <= sec[j] )
			mer[k++] = first[i++];	
		else	
			mer[k++] = sec[j++];
	}
	if( i == first_i )
		for( i = j ; i < sec_i ; i++ )
			mer[k++] = sec[i];
	else	
		for( ; i < first_i ; i++ )
			mer[k++] = first[i];
}
void mergesort( int *mer, int size)
{
	int *first, *sec, first_i = 0, sec_i = 0, i;
	first = (int *)calloc(size/2+1, sizeof(int));
	sec = (int *)calloc( size/2+1, sizeof(int));
	if( size > 1){
		for( i = 0 ; i < size/2 ; i++ )	
			first[first_i++] = mer[i];
		for( i = size/2 ; i < size ; i++)
			sec[sec_i++] = mer[i];
		mergesort( first, first_i );
		mergesort( sec, sec_i );
		merge_them( first, first_i, sec, sec_i, mer, size);
	}
}
void main()
{
	int *mer;
	long int  i, size = 1000000, count;
	clock_t start,end;
	double time_taken;
	system("clear");
	srandom(time(NULL));
	mer = (int *)calloc(size, sizeof(int));
	for( count = 50000 ; count <= size ; count+=50000 ){
		for( i = 0 ; i < count ; i++ )
			mer[i] = random()%100000;
		start = clock();
		mergesort( mer, count);
		end = clock();
		time_taken = (double)(end-start)/CLOCKS_PER_SEC;
		printf("%ld %g\n",count,time_taken);
	}
}

		
