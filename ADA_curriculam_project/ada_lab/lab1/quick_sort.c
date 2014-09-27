#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a, int *b);
int partition(int *quick, int left, int right);
void quicksort( int *quick, int left, int right);



main()
{
	int *quick, size = 1000000,  i;
	long int count;
	clock_t start, end;
	double time_taken;
	
	system("clear");
	srandom(time(NULL));
//	printf("Enter no: of numbers you wish to generate : ");
//	scanf("%d",&size);
	
	quick = (int *)calloc(size, sizeof(int));
	
	for( count = 50000 ; count <= size ; count+=50000 ){
		for( i = 0 ;  i < count ; i++ )
			quick[i] = random()%100000;
		
		start = clock();
		quicksort( quick, 0, count-1);
		end = clock();
		
		time_taken = (double)(end-start)/CLOCKS_PER_SEC;
		
		printf("\n%ld %g",count, time_taken);
	}
}	
		
			
void quicksort( int *quick, int left, int right){
	int split;
	
	if( left < right ){
		split = partition(quick, left, right);
		quicksort(quick, left    , split-1);
		quicksort(quick, split+1 , right);
	}
}

int partition(int *quick, int left, int right){
	int pivot, i, j, temp;
	
	pivot = quick[left];
	i = left;
	j = right+1;
	do{
		while(quick[++i] < pivot);
		while(quick[--j] > pivot);
		swap(&quick[i], &quick[j]);
	}while(i < j );
	swap( &quick[i], &quick[j]);
	swap( &quick[left], &quick[j]);
	return j;
}	
	

void swap(int *a, int *b){		
	int temp;
	temp 	 = 	*a;
	*a 	 =	*b;
	*b 	 = 	temp;
}



