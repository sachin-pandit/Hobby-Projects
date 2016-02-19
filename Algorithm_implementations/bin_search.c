#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void search(int *bin, int low, int high, int key){
	if( low < high){
		int mid = (low + high)/2;
		if( bin[mid] == key)
			printf("Key found in position %d",mid+1);
		else if( bin[mid] > key)
			search( bin, low, mid, key);
		else if( bin[mid] < key)
			search( bin, mid, high, key);
	}
}

main()
{
	int *bin, size, i, key, max, j;
	clock_t  start, end;
	double tim;
	
	srandom(time(NULL));
	system("clear");
	
	printf("Enter no: of numbers to be generated : ");
	scanf("%d",&size);
	
	bin = (int *)malloc(sizeof(int));
	for( i = 0 ; i < size ; i++ )
		bin[i] = random() % 10000;
		
	for( i = 0 ; i < size ; i++ ){
		max = 0;
		for( j = 0 ; j < size - i ; j++ ){
			if( bin[max] < bin[j] )
				max = j;
		}
		int temp = bin[max];
		bin[max] = bin[j-1];
		bin[j-1] = temp;
	}
	
	printf("The generated numbers are\n");
	for( i = 0 ; i < size ; i++){
		if( i % 15 == 0)
			printf("\n");
		printf("%8d",bin[i]);
	}
		
	printf("\nEnter the key to be searched : ");
	scanf("%d",&key); 
	
	start = clock();
	
	search( bin, 0, size, key);
	
	end = clock();
	
	tim = (double)(end - start)/CLOCKS_PER_SEC;
	
	printf("\nTime taken = %g\n",tim);
	
}
