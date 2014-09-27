extern int a, b;

void *flight_control(){
	int off = 20;
	int x = getmaxx(), y = getmaxy();
	
	while( c != 'q' ){

		c = getchar();
		if( c == 's' ){
			if(b + 65 + 30 < y - off)
				b += off;
		}

		else if( c == 'w' ){
			if(b - 65 + 30 >= off)
				b -= off;
		}

		else if( c == 'd' ){
			if(a + 65 + 50 < x - off)
				a += off;
		}

		else if( c == 'a' ){
			if(a - 65 + 50 >= off)
				a -= off;
		}
		//delay(100);
	}
}
