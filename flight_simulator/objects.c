extern int arr[];

void call_stars(int m, int maxx){
	int i = 0;
	int var, color;
	while( i < 200 ){
		var = arr[i] - m;
		if( var < 0 )
			arr[i] = arr[i] + maxx;
		color = random()%16;
		putpixel( (arr[i]-m), arr[i+1], color);
		i += 2;
	}
	setcolor(3);
}

void objects_top(){
	int off1 = 25, off2 = 10, off3 = 5, maxx = getmaxx(), m = 0;
	int i1, i2, i3, j1, j2, j3;
	
	i1 = maxx - off1; j1 = 40;
	i2 = maxx - off2; j2 = 200;
	i3 = maxx - off3; j3 = 300;
	
	while( c != 'q' ){
		cleardevice();
		call_stars(m, maxx);
		m += 2;
		m = m%maxx;
		
		if(i1 < maxx-off1)
			rectangle( i1, j1, i1+off1, j1+off1 );
		
		if(i2 < maxx-off2)
			rectangle( i2, j2, i2+off2, j2+off2 );
			
		if(i3 < maxx-off3)
			rectangle( i3, j3, i3+off3, j3+off3 );
			
		i1 -= off1;
		if( i1 < off1 )
			i1 = 700;
			
		i2 -= off2;
		if( i2 < off2 )
			i2 = 700;
			
		i3 -= off3;
		if( i3 < off3 )
			i3 = 700;
		call_flight();
		delay(200);
	}
} 

void *objects(){
	while( c != 'q'){
		objects_top(c);
	}
}

