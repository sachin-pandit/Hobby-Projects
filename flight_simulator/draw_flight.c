extern int a, b;
extern char c;
int color = 11;
extern int total;

void call_flight(){
	setcolor(0);
	circle( a+50, b+30, 65);
	floodfill(a+50, b+30, 0);
	
	setcolor(7);
	circle(a+50, b+30, 65);
	
	setcolor(9);
	//flight outer boundary
	line( a, b, a+20, b+20 );
	line( a, b, a, b+40 );
	line( a+20, b+20, a+80, b+20 );
	line( a+80, b+20, a+100, b+40 );
	line( a, b+40, a+100, b+40 );
	floodfill( a+75, b+27, 9);
	setcolor(10);	
	rectangle( a+70, b+24, a+80, b+30 );
	floodfill( a+75, b+27, 10);
	line( a+100, b+40, a+110, b+40 );
	setcolor(3);
	color = getpixel ( a+ 120, b+40);
	if( color == 3 )
		total += 5;
		
	
}  	
	

