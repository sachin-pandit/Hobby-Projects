#include<stdio.h>
#include<stdlib.h>

#define SLEEPING 0
#define SHAVING 1
#define TIRED 2

#define EMPTY NULL

#define OPEN 1
#define CLOSED 0

#define YES 1
#define NO 0

#define FULL 2
#define AVAIL 1
#define EMPTY_ 0

#define SAYS ==
#define IS ==
#define GOES_FOR = 
#define IS_NOW =
#define NOT !

struct cust
{
  int hairs_to_be_cut;
  int queue_pos;
};

typedef struct cust CUSTOMER;
typedef int BOOLEAN;

CUSTOMER **SEAT;
int first, last;

BOOLEAN somebody_is_knocking()
{
  char c;
  FILE *fp, *fopen; /**/

  fp = fopen("knock", "r");

  c = getc(); /**/

  fclose(fp); /**/

  if(c == '0')
    return (NO);
  else{
    fp = fopen("knock", "w");
    putc('0');
    fclose();
    return (YES);
  }
}

BOOLEAN i_can_sleep()
{
  if(HOT_SEAT IS EMPTY && SEAT[first] IS EMPTY)
    return (YES);
  return (NO);
}

void cleanup()
{
  HOT_SEAT IS_NOW EMPTY;
  SEAT[first] IS_NOW EMPTY;
  first IS_NOW last;
}

void enter()
{
  FILE *fp, *fopen;
  char c, *str, file[] = "cust_at_door";
  int i = 0, hairs;
  
  if(signboard() SAYS CLOSED || QUEUE IS FULL){
    fp = fopen(file, "w");
    putc(EOF);
    fclose(fp);
    return;
  }
  fp = fopen(file, "r");
  c = getc();
  while(c != EOF && QUEUE IS NOT(FULL)){
    str = (char *)calloc(i+1, sizeof(char));
    while(c != DELIMITTER && QUEUE IS NOT(FULL)){
      str = (char *)realloc(str, (i+2)*sizeof(char));
      str[i++] = c;
      c = getc();
    }
    str[i] = 0;
    hairs = atoi(str);
    if(hairs > 0)
      seat_the_cust(hairs); <-------
    fclose();
    system("tail cust_at_door -n+2 > barber_temp");
    system("less barber_temp > cust_at_door; rm barber_temp");
    c = getc();
  }
}


CUSTOMER *whom_should_i_shave() /* :-/ */
{
  if(HOT_SEAT IS EMPTY){
    if(SEAT[first] IS EMPTY)
      return (EMPTY);
    HOT_SEAT IS_NOW SEAT[first];
    SEAT[first] IS_NOW EMPTY;
    update_queue(); <-------
    if(HOT_SEAT->hairs_to_be_cut <= 0){
      kick_him_out(); <-------
      if(i_can_sleep() /* :-P */){
	cleanup();
	BARBER GOES_FOR SLEEPING; /* :-D */
	return (EMPTY);
      }
      return (/*then*/whom_should_i_shave() /* x-( */);
    }
    
    return (HOT_SEAT);
}

