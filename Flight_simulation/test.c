#include<stdio.h>
#include<graphics.h>

int arr[200];
int indx;

int main(){
	int gd = DETECT, gc;
	int maxx, maxy, mdx = 0, mdy = 0, adx = 0, ady = 0, i;
	char c;
	
	indx = 0;
	while( indx < 100 ){
		arr[indx++] = random() % 600 ;
		arr[indx++] = random() % 400 ;			
	}
	
	initgraph( &gd, &gc, "");
	
	maxx = getmaxx();
	maxy = getmaxy();
	for(indx = 0; indx < 200; indx += 2)
		putpixel(arr[indx], arr[indx+1],11);
			
	c = getchar();
	while(c != 'q'){
		if(c == 'd'){
			mdx += 2;
			mdx = mdx%maxx;
			i = 0;
			while( i < 200 ){
				if(arr[i] < mdx)
					arr[i] += maxx;
				putpixel( arr[i] - mdx, arr[i+1], 11);
				i += 2;
			}
		}
		else if(c == 'a'){
			adx += 2;
			adx %= maxx;
			i = 0;
			while(i < 200){
				if(arr[i] + adx > maxx )
					arr[i] -= maxx;
				putpixel( arr[i] + adx, arr[i+1], 11);
				i += 2;
			}
		}
		else if(c == 's'){
			mdy += 2;
			mdy %= maxy;
			i = 0;
			while(i < 200){
				if(arr[i] < mdy )
					arr[i] += maxy;
				putpixel( arr[i] - mdy, arr[i+1], 11);
				i += 2;
			}
		}
		else if(c == 'w'){
			ady += 2;
			ady %= maxy;
			i = 0;
			while(i < 200){
				if(arr[i] + ady < maxy )
					arr[i] -= maxy;
				putpixel( arr[i] + ady, arr[i+1], 11);
				i += 2;
			}
		}
		c = getchar();
			
	}
	
	getchar();
	
	return 0;
}
