extern int x, y;

void takeoff(){	
	x = 0; 
	y = 350;
		
	
	while( x < 500 ){  
		cleardevice();
		setcolor(11);
		line ( 0, 404, 280, 404 );
		setcolor(3);
		x++;
		setcolor(9);
		if( x < 200 ){
			//flight outline
			line( x, y, x+20, y+20 );
			line( x, y, x, y+40 );
			line( x+20, y+20, x+80, y+20 );
			line( x+80, y+20, x+100, y+40 );
			line( x, y+40, x+100, y+40 );
			floodfill( x+75, y+27, 9);
			
			//inner rectangle
			setcolor(10);	
			rectangle( x+70, y+24, x+80, y+30 );
			floodfill( x+75, y+27, 10);
				
		
			//wheel
			line(x+30, y+40, x+30, y+46 );
			line(x+80, y+40, x+80, y+46);
			setcolor(125);
			circle( x+30, y+50, 3);
			floodfill( x+30, y+50, 5);
			circle( x+80, y+50, 3);
			floodfill( x+80, y+50, 5);
			
		}

		else if( x < 250 ){
			y -= 1 / sqrt(3);
			line( x, y, x+20, y+20 );
			line( x, y, x, y+40 );
			line( x+20, y+20, x+80, y+20 );
			line( x+80, y+20, x+100, y+40 );
			line( x, y+40, x+100, y+40 );
			floodfill( x+75, y+27, 9);
			
			//inner rectangle
			setcolor(10);	
			rectangle( x+70, y+24, x+80, y+30 );
			floodfill( x+75, y+27, 10);
				
		
			//wheel
			line(x+30, y+40, x+20, y+44 );
			line(x+80, y+40, x+70, y+44 );
			setcolor(125);
			circle( x+25, y+44, 3);
			floodfill( x+25, y+44, 5);
			circle( x+75, y+44, 3);
			floodfill( x+75, y+44, 5);
		}	
		else{
			y -= 1 / sqrt(3);
			line( x, y, x+20, y+20 );
			line( x, y, x, y+40 );
			line( x+20, y+20, x+80, y+20 );
			line( x+80, y+20, x+100, y+40 );
			line( x, y+40, x+100, y+40 );
			floodfill( x+75, y+27, 9);
			
			//inner rectangle
			setcolor(10);	
			rectangle( x+70, y+24, x+80, y+30 );
			floodfill( x+75, y+27, 10);
		}
		delay(.5);
	}	
}
				
