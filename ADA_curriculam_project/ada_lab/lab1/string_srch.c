#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void main()
{
	char *sen, *str;
	int i, size, *found, j, k = 0, senlen = 0;
	clock_t start,end;
	float time_taken;
	
	srandom(time(NULL));
	
	system("clear");
	
	printf("Enter no: of characters you want to generate : ");
	scanf("%d",&size);
	
	start = clock();
	sen = (char *)calloc( size , sizeof(char));
	for( i = 0 ; i < size ; i++ )
		sen[i] = random()%26 + 'a' ;
	sen[i] = '\0';
	senlen = strlen(sen);
	printf("%s , %d\n",sen, senlen);
	
	
	
	printf("\nEnter the string to be searched : ");
	str = (char *)malloc(sizeof(char));
	scanf("%s",str);
	size = strlen(str);
	printf("%d\n",size);
	
	found = (int *)malloc(sizeof(int));
	
	for( i = 0 ; i <= senlen-size ; i++ ){
		j = 0 ;
		while( sen[i+j] == str[j] && j < size )
			j++;
		if( j == size )
			found[k++] = i+1;
	}
	printf("\n");
	if( k == 0)
		printf("\nThe string not found\n");
	else	
		for( i = 0 ; i < k ; i++ )
			printf("\nString found in pos : %d",found[i]);
	end = clock(); 
	time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
	
	

	printf("\n%ld\n",CLOCKS_PER_SEC);
	printf("\nTime taken = %f\n", time_taken);
}
