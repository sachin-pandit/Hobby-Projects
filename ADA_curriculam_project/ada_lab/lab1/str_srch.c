#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
	char *str, *sen, var;
	int stringlen = 0, slen = 0, i = 0, j = 0, temp = 0;
	
	system("clear");
	
	
	printf("\nEnter no: of characters : ");
	scanf("%d",&slen);
	sen = (char *)calloc(slen, sizeof(char));


	for( i = 0 ; i < slen ; i++ )
		sen[i] = random() % 26 +'a' ;
	sen[i] = '\0';
	printf("%s",sen);	
		
	str = (char *)malloc(sizeof(char));
	printf("\nEnter the string to be matched : ");
	scanf("%s",str);
	stringlen = strlen(str);
	printf("stringlen = %d\n",stringlen);
	
	for( i = 0 ; i <= slen-stringlen ; i++ ){
		j = 0 ;
		while( sen[i+j] == str[j] && j < stringlen )
			j++;
		if( j == stringlen ){
			temp = 1;
			printf("\n\nString found in (%d - %d) position\n", i+1 , i+j);
		}
	}
	
	if( temp == 0 )
		printf("\n\nString not found??????\n");
		
}
