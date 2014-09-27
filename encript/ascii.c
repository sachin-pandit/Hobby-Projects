#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main(int argc, char *argv[])
{
	int shift, len, i;
	char *str; 
	
	len = strlen(argv[1]);
	str=(char *)calloc(len + 1, sizeof(char));
	strcpy(str, argv[1]);
	str[len+1] = 0;
	
	shift = 0;
	while(shift < 26){
		for(i = 0; i < len; i++)
			printf("%c", shift+argv[1][i]);
		printf("\n");
		shift++;
	}
}
