#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define OCCUPIED 1
#define FREE 0

struct person{
	int value, 
	    time, 
	    pos ;
};

struct person *barber,*customer; 
	
	 
int wait_customer_limit=5;		/* Number of seats in waiting Queue */
    
int barber_count;
int pos = 0, timer = 0;

void open_the_shop();				/* This function initiates the process in barber shop */
int wake_up_barber(int next_customer);		/* Whenever customer enters the shop if hot seat is empty this call is initiated */
void clear_seat(int timer);			/* Whenever customer leaves the shop after finishing his job this call is initiated */
void check_the_q(int next_customer);		/* Customer enters the shop and finds that hot seats are full, then he will check the Queue */
int check_if_free();				/* Check for free hot seats */
int check_customer_q();				/* check for free customer queue seats */
int get_position();				/* get position of customer who has been waiting for long time*/
int get_position_free();			/* get free position in customer waiting queue */



main()
{
	
	int i;
	
	system("clear");
	srandom(time(NULL));
	
	printf("Enter the number of barbers : ");
	scanf("%d",&barber_count);
	
	customer = (struct person *)calloc( wait_customer_limit, sizeof(struct person));
	barber = (struct person *)calloc( barber_count+1, sizeof(struct person));

	open_the_shop();
		
}

void open_the_shop(){
	int flag = 1, next_customer, i;
	printf("\nThe Shop is now open\n");

	while( flag ){
		
		//sleep(2);
		
		timer = timer + 1;
		
		for( i = 0 ; i < barber_count+1 && barber[i].value == 0 ; i++ )
			barber[i].time++;						// barber status is recorded 
			
		for( i = 0 ; i < wait_customer_limit ; i++ ){
			if( customer[i].value > 0 )
				customer[i].time++;					// customer waiting status is recorded
		}
		
		clear_seat(timer);
		
		sleep(2);
		
		if( random()%2 == 0 ){
			next_customer = random()%9 + 1;
			printf("\n\t\t<--------Customer %d entered, cutting time = %d\n",timer, next_customer);
			
		
			sleep(1);
			check_the_q(next_customer);
		}
		
/*
		printf("Barber Seat status : \n");
		for( i = 1 ; i < barber_count ; i++ )
			printf("%6d",barber[i].time);
		printf("\n");
*/		sleep(1);
		
		printf("\n---------------------------------------------------------------------------------------");
		printf("\n\t\t\t\t\t\t\t\tTimer = %d\n",timer);
		printf("\nBarber Seat time status : \n");
		for( i = 1 ; i < barber_count+1 ; i++ )
			printf("%6d",barber[i].value);
		usleep(100);
		
/*		
		printf("Customer Waiting seat status : \n");
		for( i = 0 ; i < wait_customer_limit ; i++ )
			printf("%6d",customer[i].time);
*/
		sleep(1);
		printf("\nCustomer Burst Time : \n");
		for( i = 0 ; i < wait_customer_limit ; i++ )
			printf("%6d",customer[i].value);
		printf("\n---------------------------------------------------------------------------------------");
		
		printf("\n\n\n");
		//sleep(1);
		
		for( i = 0 ; i < barber_count+1 ; i++ ){
			if( barber[i].time < timer || barber[i].value == 0 ){
				barber[i].time = timer;
				barber[i].value = 0;
				barber[i].pos = 0;
				check_the_q(0);
			}
		} 
	}
}

int wake_up_barber(int next_customer){
	int max , keep = 0, i;
	
	max = 0;
	
	for( i = 1 ; i < barber_count+1 ; i++ ){
		if( barber[i].value == 0 )
			keep = i;
		if( barber[i].time >= barber[max].time && barber[i].value == 0 )
			max = i;
	}
	
	if( max == 0 )
		max = keep ;
	if( max != 0 ){
		barber[max].time += next_customer;
		barber[max].value = next_customer;
		barber[max].pos = timer;
	}
}

void clear_seat(int timer){
	int i;
	
	for( i = 0 ; i < barber_count+1 ; i++ ){
		if( barber[i].time <= timer && barber[i].value > 0 ){
			sleep(2);
			printf("\n\t\t\t\t\t\t\t\t\t\t------->Customer %d left, cutting time %d\n",barber[i].pos, barber[i].value);
			barber[i].time = timer;
			barber[i].value = 0;
			barber[i].pos = 0;
			check_the_q(0);
		}
	}
}

void check_the_q(int next_customer){
	int i, flag_hot_seat = OCCUPIED, flag_wait_seat = OCCUPIED, max ;
	
	flag_hot_seat = check_if_free() ;
	
	if( flag_hot_seat == FREE ){
		flag_wait_seat = check_customer_q();
	
		if( flag_wait_seat == OCCUPIED ){
			pos = get_position();
			sleep(2);
			if( customer[pos].value != 0 )
			printf("\n\t\t\t\t\t^^^^^customer %d removed from queue and put in hot seat, cutting time = %d^^^^\n", customer[pos].pos, customer[pos].value);
			wake_up_barber(customer[pos].value);
			customer[pos].time = 0;
			customer[pos].value = 0;
			customer[pos].pos = 0;
		}
		if( next_customer != 0 && flag_hot_seat == FREE ){
			flag_wait_seat = check_customer_q();
	
			if( flag_wait_seat == FREE )
				wake_up_barber(next_customer);
	
			else{
				pos = get_free_position();
				if( pos >= 0 ){
					sleep(2);
					if( next_customer != 0 )
					printf("\t\t----customer %d moved to queue , cutting time = %d----\n", timer, next_customer);
					customer[pos].value = next_customer;	
					customer[pos].time = 1 ;
					customer[pos].pos = timer;	
				}
			}
		}
	}
	
	else if( flag_hot_seat != FREE ){
		pos = get_free_position();
		if( pos >= 0 ){
			sleep(2);
			if( next_customer != 0 )
			printf("\t\t----customer %d moved to queue , cutting time = %d----\n", timer, next_customer);
			customer[pos].value = next_customer;
			customer[pos].time = 1 ;
			customer[pos].pos = timer;
		}
	}
	
	else{
		sleep(2);
		printf("\n\t\t--------->customer %d left, cutting time = %d\n",timer,next_customer);
	}
}		
	
int check_if_free(){
	int i;
	for( i = 0 ; i < barber_count+1 ; i++ ){
		if( barber[i].value == 0 && i!= 0)
			return ( FREE );
	}
	return (OCCUPIED );
}
			
int check_customer_q(){
	int i ;
	for( i = 0 ; i < wait_customer_limit ; i++ ){
		if( customer[i].value > 0 )
			return (OCCUPIED); 
	}
	return (FREE);
}

int get_position(){
	int i, max = 0;
	for( i = 1 ; i < wait_customer_limit ; i++ ){
		if( customer[i].time > customer[max].time){
			max = i;
		}				
	}
	return max;
}		
		
int get_free_position(){
	int i;
	for( i = 0 ; i < wait_customer_limit ; i++ ){
		if( customer[i].value == 0 )
			return i;
	}
	return -9;
}		
		
	
	
		
	
