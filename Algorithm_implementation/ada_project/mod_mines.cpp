#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<iomanip>
#include<cstdio>
#include<cstring>

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
#define WIN 1
#define LOST 0


using namespace std;

void welcome(void);
void initialize(char board[11][11]);
int  numofmines(int mines);
int  minespos(char board[11][11]);
void init_numboard(char board[11][11]);
void assign_num(char board[11][11], int, int);
void call_play(char board[11][11],int count_mines);
void display_num();
void display_board(char board[11][11], int count_mines, int LABEL);
void dynamic(char board[11][11], int x, int y);
void init_newboard(void);
void uncover(char board[11][11], int x, int y);
void countstar(char board[11][11], char new_num[11][11],int *count_u, int *count_f);
void call_win(void);


char num[11][11], new_num[11][11];
int numofit = 0, reveal = 0;


// MAIN PROGRAM
main()
{
	
	char board[11][11];
	int i, j, mines = 1, count_mines = 0;
	
	system("clear");
	
	welcome();
	
	initialize(board);
	
	initialize(num);

	count_mines = minespos(board);
	
	init_numboard(board);
	
	init_newboard();
	
	call_play( board,count_mines);	

}



//WELCOME FUNCTION
void welcome(){
	for(int i = 17 ; i < 100 ; i++ ){
		system("clear");
		cout << setw(i) << (DARK_BROWN"WELCOME TO MINES\n"RESET_COLOR);
		cout << (BLUE"( )     ( )     ( )     ( )     ( )     ( )\
  X       X       X       X       X       X\
-' `-. ,-' `-. ,-' `-. ,-' `-. ,-' `-. ,-' `-. ,\
      X       X       X       X       X       X\
     (_)     (_)     (_)     (_)     (_)     (_)\
 "RESET_COLOR);
		sleep(.9);
	}
	cout << endl; 
	cout << (DARK_BROWN"\n");
	cout << (BACK_GREEN"\
\t\t\t\t\t ##     ##  ####  ##    ##  ########   ######.\n\
\t\t\t\t\t ###   ###   ##   ###   ##  ##        ##    ##\n\
\t\t\t\t\t #### ####   ##   ####  ##  ##        ##      \n\
\t\t\t\t\t ## ### ##   ##   ## ## ##  ######     ###### \n\
\t\t\t\t\t ##     ##   ##   ##  ####  ##              ##\n\
\t\t\t\t\t ##     ##   ##   ##   ###  ##        ##    ##\n\
\t\t\t\t\t ##     ##  ####  ##    ##  ########   ###### \n\
"RESET_COLOR);

}


// INITIALIZE THE BOARD
void initialize(char board[11][11]){
	for( int i = 0 ; i <= 11 ; i++ ){
		for( int j = 0 ; j <= 11 ; j++ ){
			board[i][j] = 'r';
		}
	}
}




// RETURN NO: MINES
int numofmines(char mines){
	if( mines == '1')
		return 13;
	else if( mines == '2')
		return 28;
	else if( mines == '3')
		return 40;
	else
		return 0;
}



// INITIALIZE NUMBER BOARD
void init_numboard(char board[11][11]){
	
	for( int i = 1 ; i < 11 ; i++ ){
		for(int  j = 1 ; j < 11 ; j++ ){
			assign_num( board, i, j);
		}
	}	
}


// ASSIGN NO: OF BOMBS IN ITS SURROUNDINGS
void assign_num(char board[11][11], int m ,int n){
	int count = 0;
	char var;
	for(int i = m-1 ; i <= m+1 ; i++ ){
		for(int j = n-1 ; j <= n+1 ; j++ ){
			if(( i != m || j != n) && board[i][j] == '*'){
				count++;
			}
		}
	}
	num[m][n] = count+'0';
}	




// INITIALIZE POSITION OF MINES
int minespos(char board[11][11]){
	char mines;
	int count_mines = 0, no_mines;
	op :	printf(BLUE "Easy   = 1\nMedium = 2\nHard   = 3\n" RESET_COLOR );
			printf(DARK_BROWN "CHOOSE A VALID OPTION: " RESET_COLOR);
			cin >> mines;
			no_mines = numofmines(mines);
			system("clear");
			if( no_mines == 0){
				cout << "INVALID choice!!!!\n";
				goto op;
			}
	
		srand(time(0));
	
		while(no_mines){
			int i = rand()%10;
			int j = rand()%10;
			if( ( i > 0 && i < 9) && (j > 0 && j < 9 ) && board[i+1][j+1] != '*'){
				board[i+1][j+1] = '*';
				count_mines++;
			}
			no_mines--;
		}	
	return(count_mines--);
}






// DISPLAY THE NUMBER BOARD
void display_num(){
	int i, j , k = 0;
	system("clear");
	cout << setw(55) << (BACK_GREEN"DYNAMIC BOARD"RESET_COLOR)<< setw(60) 
		 << (BACK_GREEN"REFERENCE BOARD\n"RESET_COLOR);
	cout << "\n\n";
	while( k < 2){
		cout << "\t\t\t" ; printf(BACK_GREY"%5c"RESET_COLOR,'1');
		for( i = 2 ; i < 10 ; i++ )
			printf(BACK_GREY"%3d"RESET_COLOR,i);
		k++;
	}
	cout << "\n\t\t\t" << (BACK_BLUE"_____________________________"RESET_COLOR) << "\t\t\t"
			 << (BACK_BLUE"_____________________________"RESET_COLOR) << endl;
	for( int k = 1, i = 1; i < 10 ; i++, k++ ){
		cout << "\t\t\t" << k << (BACK_BLUE"|"RESET_COLOR);
		for( j = 1 ; j < 10 ; j++ ){
			if( new_num[i][j] == 'F')
				printf(GREEN"%3c"RESET_COLOR,'F');
			else
				printf(BLUE"%3c"RESET_COLOR,new_num[i][j]);
		}
		cout << "\t\t\t" << i << (BACK_BLUE"|"RESET_COLOR);
		for( j = 1 ; j < 10 ; j++ ){
			printf("%3c",num[i][j]);
		}
		cout << endl;
	}
}	








// DISPLAY BOARD CONTAINING BOMBS AFTER LOSING THE GAME
void display_board(char board[11][11], int count_mines, int LABEL){
	int i;
	
		for(int i = 17 ; i < 95 ; i++ ){
			system("clear");
			if( LABEL == 0)
				cout << setw(i) << (DARK_BROWN"YOU LOST!!!!!!!\n"RESET_COLOR);
			else
				cout << setw(i) << (DARK_BROWN"YOU WON !!!!\n"RESET_COLOR); 
			sleep(.9);
		}
		cout << (BACK_LIGHT_BROWN"The board looks like this : "RESET_COLOR);
		cout << "\n\n\n\n\n\n";
		cout << setw(42) << " ";
		for( i = 1 ; i < 10 ; i++ )
			printf(BACK_GREY"%3d"RESET_COLOR,i);
		cout << (BACK_BLUE"\n\t\t\t\t\t_____________________________\n"RESET_COLOR);
		for( i = 1 ; i < 10 ; i++ ){
			cout << "\t\t\t\t\t" << i << (BACK_BLUE"|"RESET_COLOR);
			for(int  j = 1 ; j < 10 ; j++ ){
				if( board[i][j] == '*' )
					printf(DARK_BROWN"%3c"RESET_COLOR,'@');
				else
					printf(BLUE"%3c"RESET_COLOR,board[i][j]); 
			}
			cout << endl;
		}	
		cout << "\nMINES = " << count_mines << endl;		
		sleep(.5);
}



// FUNCTION TO PLAY THE GAME WITH INPUT FROM USER 
void call_play(char board[11][11], int count_mines){
	int x, y, k=0, temp = 1, check = 1, count = 0, count_u = 0, count_f = 0, assign_flag = 0,minesnum;
	int count_wrong = 0;
	char choice, pos1, pos2;
	
	while(temp != 0){
disp:	display_num();
//		display_board(board, count_mines, 0);
		cout << "COUNT_U = " << count_u << "\t" ;
		cout << "COUNT_F = " << count_f << "\t";
		cout << "COUNT_MINES = " << count_mines << "\n";
		cout << "ASSIGN_Flag = " << assign_flag << "\t";
		cout << "COUNT_WRONG = " << count_wrong << "\n";
out:	cout << "\nEnter the row number : ";
		cin  >> pos1 ;
		cout << "Enter the column number : ";
		cin  >> pos2 ;
		x = (pos1 - '0');
		y = (pos2 - '0');
		if( x < 10 && x > 0 && y < 10 && y > 0){	
in:			cout << "\nwhat do you want to do?\n";
  			cout << "Insert a flag 	  - (f)\nUnlock the cell   - (u)\n";
			cout << "Enter your choice : " ;
			cin  >> choice;
			cout << board[x][y] << endl;
			if( choice == 'u'){
				if( board[x][y] != '*'){
					if(new_num[x][y] != '#'){
						new_num[x][y] = '#';
						reveal = 0;
						dynamic(board, x, y);
						count++;
					}
				}
				else if( board[x][y] == '*'){
					if( count == 0 ){
						new_num[x][y] = 'F';
						count_f++;
						continue;
					}
					temp = 0;
					display_board(board, count_mines, 0 );
				}
			}	
			
			else if( choice == 'f'){
				if(new_num[x][y] == '-'){
					new_num[x][y] = 'F';
					assign_flag++;
					count++;
				}
			}
			
			else{	
				cout << "Invalid choice!!!\n";
				goto in;
			}
			
		}
		
		else{
			cout << "INVALID POSITION\n";
			goto out;
		} 
		countstar(board, new_num, &count_u, &count_f);
		if( count_u == (81-count_mines)  || count_f == count_mines ){
				system("clear");
				cout << "COUNT_U = " << count_u << "\t" ;
				cout << "COUNT_F = " << count_f << "\t";
				cout << "COUNT = " << assign_flag << "\t";
				cout << "COUNT_MINES = " << count_mines << "\n";
				display_board(board, count_mines, 1 );
				return;
		}
		if( assign_flag > count_mines && choice == 'f'){
			system("clear");
			cout << (DARK_BROWN"NUMBER OF FLAGS IS GREATER THAN MINES!!!!\n"RESET_COLOR);
			sleep(2);
			system("clear");
			cout << (BLUE"GUESS WORK DOESNT WORK HERE :)\n"RESET_COLOR);
			sleep(2);
			system("clear");
			cout 
			<< (MAGENTA"YOU WILL LOSE IF YOU \"FLAG\" 10 WRONG PLACES FROM NOW ONWARDS!\n"RESET_COLOR);
			sleep(4);
			count_wrong++;
			goto disp;
		}
		if( count_wrong > 10 ){
			cout << (DARK_BROWN"YOU LOST BECAUSE OF EXCEEDING MAX GUESS!!!! }:-) \n"RESET_COLOR);
			sleep(5);
			display_board(board, count_mines, 0);
			return;
		}
		numofit++;
	}		
}



// INITIALIZE NEW BOARD
void init_newboard(){
	for( int i = 0 ; i <= 11 ; i++ ){
		for( int j = 0 ; j <= 11 ; j++ ){
			new_num[i][j] = '-';
		}
	}
}
		

// DYNAMIC UNCOVERING OF CELLS IN A BOARD
void dynamic(char board[11][11], int x, int y){
	for(int i = x-1 ; i <= x+1 ; i++ ){
		for( int j = y-1 ; j <= y+1 ; j++){
				if( num[i][j] == '0' && board[i][j] != '*'){
					if( i > 0 && i < 10 && j > 0 && j < 10){
						num[i][j] = '#';
						new_num[i][j] = '#';
						dynamic(board, i, j);
					}
				}
				if( board[i][j] != '*')
					new_num[i][j] = num[i][j];
		}
	} 
	new_num[x][y] = '#';
	return;
}




// FUNCTION TO UNCOVER RECURSIVELY	
void uncover(char board[11][11], int x, int y){
	
}
	

// RETURNS NUMBER OF UNCOVERED AND FlAGGED CELLS
void countstar(char board[11][11], char new_num[11][11],int *count_u, int *count_f){
	*count_u = 0;
	*count_f = 0;
	for(int i = 1 ; i < 10 ; i++ ){
		for( int j = 1 ; j < 10 ; j++ ){
			if( new_num[i][j] == '#' ||( new_num[i][j] >= '1' && new_num[i][j] <= '9'))
				*count_u = *count_u + 1;
			if( new_num[i][j] == 'F' && board[i][j] == '*')
				*count_f = *count_f + 1;
		}
	}
	return;
}
				 
				 
				 
				 
				 
				 
/*DYNAMIC BOARD
void dynamic(char board[11][11], int x, int y){
	for(int i = x-1 ; i <= x+1 ; i++ ){
		for( int j = y-1 ; j <= y+1 ; j++){
				if( num[i][j] == '0' && board[i][j] != '*'){
					new_num[i][j] == '#';
					uncover(i ,j);
				}
				if( numofit == 0 || ( board[i][j] != '*' && i == j ))	
				else
					new_num[i][j] = num[i][j];
		}
	} 
	new_num[x][y] = '#';
	return;
}*/
	
		
