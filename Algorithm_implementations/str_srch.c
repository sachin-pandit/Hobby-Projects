#include"header.h"
#include<string.h>

void main()
{
	int i, j, flag ;
	char *sen, *str;
	FILE *fp;
	
	system("clear");
	
	fp = fopen("str_srch.c", "r" );
	sen = (char *)malloc(sizeof(char));
	
	for( i = 0 ; sen[i-1] != EOF ; i++ ){
		sen[i] = getc(fp);
		printf("%c",sen[i]);
	}
	sen[i] = '\0';
	int senlen = strlen(sen);
	
	str = (char *)malloc(sizeof(char));
	printf("Enter the string to be searched : ");
	scanf("%s", str );
	int strleng = strlen(str);
	
	flag = 0;
	for( i = 0 ; i < senlen-strleng; i++ ){
		j = 0;
		while( sen[i+j] == str[j] && j < strleng )
			j++;
		if( j == strleng){
			printf("String found in %d position\n",i+1 );
			flag = 1;
		}
	}
	if( flag == 0 )
		printf("String not found \n");
}
	
		
	
	
	
