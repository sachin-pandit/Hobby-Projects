#include<iostream>
#include<cstdlib>
#include<cstdio>



#define BLUE    		"\033[22;34m"
#define MAGENTA  		"\033[22;35m"
#define CYAN  			"\033[22;30m"
#define GREY  			"\033[22;37m"
#define GREEN 			"\033[22;32m"
#define YELLOW  		"\033[22;33m"
#define LIGHT_CYAN  	"\033[22;36m"
#define WHITE  			"\033[22;37m"
#define DARK_BROWN  	"\033[22;31m"

#define BACK_BROWN  		"\033[22;41m"
#define BACK_GREEN  		"\033[22;42m"
#define BACK_LIGHT_BROWN  	"\033[22;43m"
#define BACK_BLUE  			"\033[22;44m"
#define BACK_PINK  			"\033[22;45m"
#define BACK_LIGHT_BLUE  	"\033[22;46m"
#define BACK_GREY  			"\033[22;47m"



#define RESET_COLOR "\e[m"
#define MAKE_GREEN "\e[32m"

main()
{
system("clear");
printf(BLUE "this will show up in BLUE" RESET_COLOR "\n");
printf(MAGENTA "this will show up in MAGENTA" RESET_COLOR "\n");
printf(CYAN "this will show up in CYAN" RESET_COLOR "\n");
printf(GREY "this will show up in GRAY" RESET_COLOR "\n");
printf(GREEN "this will show up in LIGHT_GREEN" RESET_COLOR "\n");
printf(YELLOW "this will show up in YELLOW" RESET_COLOR "\n");
printf(LIGHT_CYAN "this will show up in LIGHT_CYAN" RESET_COLOR "\n");
printf(WHITE "this will show up in WHITE" RESET_COLOR "\n");
printf(DARK_BROWN "this will show up in DARK_BROWN" RESET_COLOR "\n");
//printf(GREY "this will show up in UNKNOWN" RESERT_COLOR "\n");
printf( BACK_BROWN "this will show up in BACK_BROWN"RESET_COLOR "\n");
printf( BACK_BROWN"this will show up in BACK_BROWN"RESET_COLOR "\n");
printf( BACK_LIGHT_BROWN"this will show up in BACK_LIGHT_BROWN"RESET_COLOR "\n");
printf( BACK_BLUE"this will show up in BACK_BLUE"RESET_COLOR "\n");
printf( BACK_PINK"this will show up in BACK_PINK"RESET_COLOR "\n");
printf( BACK_LIGHT_BLUE"this will show up in BACK_LIGHT_BLUE"RESET_COLOR "\n");
printf( BACK_GREY"this will show up in BACK_GREY"RESET_COLOR "\n");

}


















