#include <stdio.h>
#include <graphics.h>

void objects();
void call_flight();
void flight_control();
void objects_top(char);

char c = 'x';
int a = 100, b = 100;
pthread_t t1, t2;

