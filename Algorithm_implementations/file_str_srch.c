#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void main()
{
	char *sen, *str;
	int i = 0, senlen=0, strglen=0, j = 0, temp = 0;
	clock_t start, end;
	double time_taken;
	FILE *fp;
	
	system("clear");
	
	fp = fopen("file_str_srch.c", "r" );
	
	sen = (char *)malloc(sizeof(char));
	
	for( i = 0 ; sen[i-1] != EOF ; i++ ){
		sen[i] = getc(fp);
	}
	sen[i++] = '\0';
	senlen = strlen(sen);
	
	printf("\nThe read characters are : ");
	for( i = 0 ; i < senlen-1 ; i++ )
		printf("%c",sen[i]);
	
	str = (char *)malloc(sizeof(char));
	printf("\nEnter the string to be searched : ");
	scanf("%s",str);
	strglen = strlen(str);
	
	start = clock();
	for( i = 0 ; i <= senlen-strglen ; i++){
		j = 0;
		while( sen[i+j] == str[j] && j < strglen )
			j++;
		if( j == strglen ){
			temp = 1;
			printf("\nThe string is found in position %d",i+1);
		}
	}
	end = clock();
	
	time_taken = (double)(end-start)/CLOCKS_PER_SEC;
	
	printf("\n");
	if( temp == 0)
		printf("\nString not found\n");		
	printf("\nTime taken = %g\n",time_taken);
}
		
	
	
	
