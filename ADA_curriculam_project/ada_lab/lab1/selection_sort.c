#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main()
{
	int *sel, i, j, size, max;
	clock_t begin,end;	
	double tim;
	
	srandom(time(NULL));
		
	system("clear");
	

		
	printf("Enter the size of an array\n");
	scanf("%d",&size);
	sel = (int *)calloc(size,sizeof(int));
	
	for( i = 0 ; i < size ; i++ )
		sel[i] = random()%10000;

	begin = clock();

	for( i = 0 ; i < size ; i++ ){
		max = 0;
		for( j = 0 ; j < size - i ; j++ ){
			if( sel[max] < sel[j] )
				max = j;
		}
		int temp = sel[max];
		sel[max] = sel[j-1];
		sel[j-1] = temp;
	}
	
	end = clock();
	
	tim = (double)(end - begin)/CLOCKS_PER_SEC;
	
	
	printf("The sorted array is as follows\n");
	for( i = 0 ; i < size ; i++ ){
		if( i % 10 == 0 && i != 0)
			printf("\n");	
		printf("%13d",sel[i]);
	}
	printf("\nTime taken = %g\n",tim);

}
			
