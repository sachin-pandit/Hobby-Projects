
extern int arr[];
extern int indx;

get_objects(){
	indx = 0;
	while( indx < 200 ){
		arr[indx++] = rand() % 600 ;
		arr[indx++] = rand() % 400 ;			
	}
}
