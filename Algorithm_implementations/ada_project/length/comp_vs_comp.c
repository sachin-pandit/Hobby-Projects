/*******************************

LENGTH CONQUER
-Played by Two Players
-Alternate Turns
-Goal is to cover a total length in a scale
-To achieve the goal three small scales are used
-Each Player chooses one of the three small scales each time
-If the whole scale is covered exactly then the game is a draw
-Else the Player who covered the scale last is the winner

Example : Run the programme with the following inputs : L = 40, x = 3, y = 4, z = 5

******************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*zone priorities*/
#define SAFE 2
#define DRAW SAFE-1
#define UNSAFE DRAW-1
#define NIL -1

#define SWAP(A, B) {temp = *A; *A = *B; *B = temp;}

/*colour codes*/
#define RED "\033[22;41m"
#define BLUE "\033[22;44m"
#define WHITE "\033[22;37m"
#define LIGHT_BLUE "\033[22;46m"
#define LIGHT_BROWN "\033[22;43m"
#define RESET_COLOR "\e[m"

int *zone,     /*zone board*/
  *board;      /*game board*/

int x, y, z,   /*sub units*/
  L;           /*Length of the game board*/


char prompt()
{
  char dummy;
  
  printf("\n\n\n\nPress any key...");
  dummy = getchar();
  dummy = getchar();

  return (dummy);
}

/*sorts the three sub-units*/
void sort_inputs(int *x, int *y, int *z)
{
	int temp;

	if(*x > *y)
		SWAP(x, y);	
	if(*y > *z)
		SWAP(y, z);
	if(*x > *y)
		SWAP(x, y);
}

/*validate the inputs*/
int check_inputs()
{
  int valid = 1;
  
  if(
     !(L >= 4*z)                    /*Board length should be greater than 4 times*/ 
                                    /*the greatest sub-unit*/
     ||
     (x <= 1)                       /*no sub-unit shall be unity*/
     ||
     (x == y || x == z || y == z)   /*sub-units should be distinct*/
     )
    valid = 0;

  if(valid == 0)
    printf("Invalid inputs\n");
  
  return (valid);
}

/*returns how many among the three sub-units can be selected ( - to avoid boundary conflicts)*/
int option_limit(int i)
{
  int limit;

  /*only (x) ~ 1 ; only (x,y) ~ 2 ; all (x,y,z) ~ 3 ; none () ~ 0*/
  limit = (i+x <= L) + (i+y <= L) + (i+z <= L);

  return (limit);
}

/*returns the zone to which the zone-value maps to*/
int ZONE(int Zone)
{
  if(Zone == NIL)
    return (NIL);
  if(Zone < 10)
    return (SAFE);
  if(Zone < 100)
    return (DRAW);
  return (UNSAFE);
}

/*calculates the priority of the zones to which entering is allowed*/
int priority(int Zone1, int Zone2, int Zone3)
{
  return (
	  (Zone1 != NIL)*pow(10, Zone1) 
	  +
	  (Zone2 != NIL)*pow(10, Zone2) 
	  +
	  (Zone3 != NIL)*pow(10, Zone3)
	  );

  /*
  priority map:

  priority is inversely proportional to priority value
  the lower the value, the higher the priority
  
  single choice:
  S(1U) - 1  
  D(1D) - 10
  U(1S) - 100

  
  double choice:
  S(2U) - 2
  
  D(1D,1U) - 11
  D(2D) - 20

  U(1S,1U) - 101
  U(1S,1D) - 110
  U(2S) - 200

  
  triple choice:
  S(3U) - 3
  
  D(1D,2U) - 12
  D(2D,1U) - 21
  D(3D) - 30

  U(1S,2U) - 102
  U(1S,1D,1U) - 111
  U(1S,2D) - 120
  U(2S,1U) - 201
  U(2S,1D) - 210
  U(3S) - 300
  */

}

/*sets the zone with appropriate priority, to which each step of the game belongs to*/
void mark_zones()
{
  int 
    i;     /*index*/

  zone[L-1] = priority(DRAW, NIL, NIL);
  
  for(i = L-1; i > L-x; i--)
    zone[i-1] = priority(UNSAFE, NIL, NIL);
    
  zone[L-x-1] = priority(DRAW, NIL, NIL);
  i--;
  
  for( ; i > L-y; i--)
    zone[i-1] = priority(ZONE(zone[i-1+x]), NIL, NIL);

  for( ; i > L-z; i--)
    zone[i-1] = priority(ZONE(zone[i-1+x]), ZONE(zone[i-1+y]), NIL);
  
  for( ; i >= x; i--)
    zone[i-1] = priority(ZONE(zone[i-1+x]), ZONE(zone[i-1+y]), ZONE(zone[i-1+z]));
  
  for( ; i > 0; i--)
    zone[i-1] = NIL;
  
  /*
  for(i = x+1; i < y && i < z && i < 2*x; i++)
    zone[i-1] = NIL;
  */
  
}

/*updates the game board*/
void update_board(int step, int player, int *pos) /*pos is the current game position */
{
  int i = 0;
  
  for(i = *pos; i < *pos+step; i++)
    board[i] = player;

  *pos += step;
}

/*interleaved display of gameboard and zoneboard*/
char display(int pos)
{
  int i, distance = 70, j, zz = 0;
  char auth;

  printf("Length :%3d\nSub-Units: %3d, %3d, %3d\n", L, x, y, z);
  
  printf("Current position:%3d\nBoard:", pos);

  
  for(j = 0; j < distance-6; j++)
    printf(" ");
  printf("Zones:\n");
  
  for(i = 0; i < pos; i++){
    /*game board*/
    if(board[i] == 1)
      printf(LIGHT_BLUE "%3d",i+1);
    else
      printf(LIGHT_BROWN "%3d",i+1);
    
    printf(RESET_COLOR "|");
    /*game board*/

    if((i+1)%10 == 0 || i == L-1){
      /*zone board*/
      for(j = ((i%10)*4 + 4); j < distance; j++)
	printf(" ");
      
      for(j = 0; j < 10 && zz < L; j++, zz++){
	if(ZONE(zone[zz]) == SAFE)
	  printf(BLUE "%3d", zz+1);
	if(ZONE(zone[zz]) == UNSAFE)
	  printf(RED "%3d", zz+1);
	if(ZONE(zone[zz]) == DRAW)
	  printf(WHITE "%3d", zz+1);
	if(zone[zz] == NIL)
	  printf("   ");
	printf(RESET_COLOR);
	printf("|");
      }	
      printf("\n");
      /*zone board*/
    }
  }
  
  for( ; i < L; i++){
    /*game board*/
    printf("%3d|", i+1);
    /*game board*/
    
    if((i+1)%10 == 0 || i == L-1){
      /*zone board*/
      for(j = ((i%10)*4 + 4); j < distance; j++)
	printf(" ");
      
      for(j = 0; j < 10 && zz < L; j++, zz++){
	if(ZONE(zone[zz]) == SAFE)
	  printf(BLUE "%3d", zz+1);
	if(ZONE(zone[zz]) == UNSAFE)
	  printf(RED "%3d", zz+1);
	if(ZONE(zone[zz]) == DRAW)
	  printf(WHITE "%3d", zz+1);
	if(zone[zz] == NIL)
	  printf("   ");
	printf(RESET_COLOR);
	printf("|");
      }	
      printf("\n");
      /*zone board*/
    }
  }

  auth = prompt();
}

/*asks the computer to play next move*/
int get_pos(int lim, int pos, char auth)
{
  int step;

  if(lim == 0)
    return (-1);			     /*nothing can be chosen, the game is over*/

  step = x;				     /*initial blind choice*/
  
  if(lim == 3)
    step = z;				     /*if z can be reached then let it be chosen by default*/
  if(lim >= 2)
    if(zone[pos+y-1] < zone[pos+step-1])     /*y is chosed if it leads to a safer position(with lower p-value)*/
      step = y;
  if(lim > 1)
    if(zone[pos+x-1] < zone[pos+step-1])     /*x is chosen if ...^... */
      step = x;
  
  return (step);
}

/*handles the events that happen during the game*/
int gameplay()
{
  int 
    i, 
    lim, 
    comp2 = 2, 
    board_pos = 0, 
    flag = 1,
    step;

  char auth;

  system("clear");
  printf("Let The Game Begin...\n\n\n");	
  sleep(2);
  system("clear");

  lim = option_limit(board_pos);

  printf("\nStart\n");
  auth = display(board_pos);
  system("clear");

  while(lim != 0){
    step = get_pos(lim, board_pos, auth);
    if(comp2 == 2)
      printf("\nComputer(1) chose %2d\n", step);
    else
      printf("\nComputer(2) chose %2d\n", step);
    
    flag = 1;                              /* - recently played by computer1*/
   
    update_board(step, flag, &board_pos);

    auth = display(board_pos);
    system("clear");
    
    lim = option_limit(board_pos);
    
    if(lim != 0){
      step = get_pos(lim, board_pos, auth);
      if(comp2 == 2)
	printf("\nComputer(2) chose %2d\n", step);
      else
	  printf("\nComputer(1) chose %2d\n", step);

      flag = 2;                            /* - recently played by computer2*/   

      update_board(step, flag, &board_pos);

      auth = display(board_pos);
      //printf("\n\n");
      system("clear");

      lim = option_limit(board_pos);
    }
  }

  /*the results*/
  if(board_pos == L)
    printf("\nThe game is a draw!\n");
  else{
    if(comp2 == flag)
      printf("\nComputer(2) wins!!!!\n");
    else
      printf("\nComputer(1) wins!!!!\n");
  }
  /*the results*/

  return (board_pos);
}

main()
{
  int 
    valid = 0,   /*State of Validity*/
    end_point;   /*Game's End*/
  char
    dummy;

  L = 0;

  system("clear");
  printf("Length Conquer\n\nOverview\n-Played by Two Players in alternate turns\n-Goal is to cover a total length in a scale (from one end to the other)\n-To achieve the goal three small scales are used\n-Each Player chooses one of the three small scales each time\n-If the whole scale is covered exactly then the game is a draw\n-Else the Player who covered the scale recently will be the winner\n");
  
  prompt();

  system("clear");
  while(L < 16){
    printf("Please enter the Length (16 <= L)..\n");
    scanf("%d", &L);
  }

  system("clear");
  while(valid == 0){
    printf("\n\n\nPlease enter three sub-units such that they\n1)are less than %d\n2)are not equal to unity\n3)are unequal\n\n", L/4);
    scanf("%d%d%d", &x, &y, &z);
    sort_inputs(&x, &y, &z);
    valid = check_inputs();
  }

  zone = malloc(L*sizeof(int));
  board = malloc(L*sizeof(int));
  
  sort_inputs(&x, &y, &z);
  
  mark_zones();
  
  end_point = gameplay();
  
  printf("\n\nThank you for making me play (against me!!)\n");

  prompt();
  system("clear");
}
 
