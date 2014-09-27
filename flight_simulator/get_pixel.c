extern char c;
int color;

char get_pixel(int x1, int y1, int x2, int y2){
	while( y1 < y2){
		color = getpixel( x1, y1 );
		if( color == 3)
			return('q');
		y1++;
	}
	while( y2 < y1 ){
		color = getpixel( x2, y2 );
		if( color == 3)
			return('q');
		y2++;
	} 	
	
	while( x1 < x2 ){
		color = getpixel( x1, y1);
		if( color == 3)
			return('q');
		x1++;
	}

	while( x2 < x1 ){
		color = getpixel( x2, y2 );
		if( color == 3)
			return('q');
		x2++;
	}
}
