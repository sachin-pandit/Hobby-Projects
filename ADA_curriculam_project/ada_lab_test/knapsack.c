#include"header.h"

int *weight, *value, table[100][100];
int knapsack(int i, int j);

void main()
{
	int num_i, cap , i, j;
	system("clear");
	srandom(time(NULL));
	
	printf("Enter No: of items : ");
	scanf("%d",&num_i);
	printf("Enter the capacity of knapsack : ");
	scanf("%d",&cap);
		
	weight = (int *)calloc(num_i, sizeof(int));
	value = (int *)calloc(num_i , sizeof(int));
//	table = (int **)calloc(num_i, sizeof(int *));

	
	for( i = 0 ; i <= num_i ; i++ ){
//		table[i] = (int *)calloc(cap, sizeof(int));
		
		for( j = 0 ; j <= cap ; j++ ){
			if( j == 0 )
				table[0][j] = 0;
			table[i][j] = -1;
		}
		table[i][0] = 0;
	}
			
	for( i = 1 ; i <= num_i ; i++ ){
//		scanf("%d%d",&weight[i],&value[i]);
		weight[i] = random()%5+1;
		value[i]  = random()%99+1;
		printf("weight[%d] = %4d, value[%d] = %4d\n",i, weight[i],i, value[i]);
	}
	printf("\n\n");
	
	knapsack( num_i , cap );
	
	for( i = 0 ; i <= num_i ; i++ ){
		for( j = 0 ; j <= cap ; j++ ){
			printf("%7d",table[i][j]);
		}
		printf("\n");
	}
}

int knapsack(int i, int j){
	int values;
	if( table[i][j] < 0 ){
		if( j < weight[i] )
			values = knapsack( i-1, j );
		else
			values = knapsack(i-1, j) > value[i]+knapsack(i-1, j-weight[i]) ? knapsack(i-1, j) : value[i]+knapsack(i-1, j-weight[i]);  
		table[i][j] = values;
	}
	return (table[i][j]);
}


