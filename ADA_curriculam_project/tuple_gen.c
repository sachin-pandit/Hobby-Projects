#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(int argc, char *argv[] ){
	system("clear");
	int count , i , repeat=0;
	
	srandom(time(NULL));
	

	if( argc == 1 )	
		printf("No arguments \n");
	
	else{
		while( repeat < atoi(argv[2]) ){
			printf("\ninsert into %s \nvalues (",argv[1]);
			count = 3;

			while( count < argc ){
				
				if( count != 3 )
					printf(",");
				if( strcmp( argv[count],"char" ) == 0)
					printf("'%c'", random()%26+'a' );

				else if( strcmp( argv[count] , "int" ) == 0 )
					printf("'%d'", random()%100 ); 

				else if( strcmp( argv[count] , "str")  == 0){
					printf("'");
					if( count+1 < argc ){
						for( i = 0 ;  i < atoi(argv[count+1]) || i == 0  ; i++ )
							printf("%c",random()%26+'a');
					}
					printf("'");
					count++;
				}
				else if( strcmp( argv[count], "date") == 0 )
					printf("'%d-%d-%d'",random()%11+2000, random()%11+1, random()%27+1 );
				
				count++;
			}
		repeat++;
		printf(");\n");
		}
	}
}
				 
