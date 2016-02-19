#include<stdio.h>
#include<stdlib.h>

void main(int argc, char *argv[]){
	unsigned long long int hash = 0;
	char  *ptr, c;
	ptr = (char *)malloc(sizeof(argv[1]));
	ptr = argv[1];
	while (c = *ptr++)
            hash = c*3 + (c << 6) + (hash << 16) - hash;
 	hash = hash % 9;
 	printf("%llu",hash);          
} 
