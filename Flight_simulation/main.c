#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include <pthread.h>
#include "draw_flight.c"
#include "flight_control.c"
#include "objects.c"
#include "takeoff.c"
#include "landing.c"
#include "get_objects.c"
#include "welcome.c"
#include "instruct.c"

char c = 'x';
pthread_t t1;
int a = 100, b = 200;
int x = 0, y = 350;
int total = 0;
int arr[200];
int indx = 0;



void main()
{
	int gd = DETECT, gc;
	int err1, err2;
	initgraph( &gd, &gc, "");
	welcome();
	instruct();
	takeoff();
	call_flight();
	get_objects();
	err1 = pthread_create(&t1, NULL, objects, (void *)0);	
	flight_control();
	landing();
	getchar();
}

