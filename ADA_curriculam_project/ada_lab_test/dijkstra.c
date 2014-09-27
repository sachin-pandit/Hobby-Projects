#include"header.h"

void dijkstra(void );
int c[10][10], n, src;

void main()
{
	int i, j;
	system("clear");
	srandom(time(NULL));
	
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	
	printf("The cost matrix : \n");
	for( i = 1 ; i <= n ; i++ ){
		for( j = 1 ; j <= n ; j++ ){
			scanf("%d",&c[i][j]);
		}
		printf("\n");
	}
	
	printf("Enter the source node : ");
	scanf("%d", &src );
	dijkstra();
}

void dijkstra(){
	int vis[10], dist[10], v, j, count , min,i ;
	
	for( i = 1 ; i <= n ; i++ )
		dist[i] = c[src][j];
		
	for( i = 1 ; i <= n ; i++ )
		vis[i] = 0;
	
	dist[src] = 0;
	vis[src] = 1;
	count = 1;
	
	while( count != n ){
		min = 9999;
		for( i = 1 ; i <= n ; i++ ){
			if( dist[i] < min && vis[i] != 1 ){
				min = dist[i];
				v = i;
			}
		}
		vis[v] = 1;
		count++;
		for( i = 1 ; i <= n ; i++ ){
			if( min+c[v][i] < dist[i] && vis[i] != 1 ){
				dist[i] = min + c[v][i];
			}
		}
	}
	
	printf("\nThe shortest distance is : \n");
	for( i = 1 ; i <= n ; i++ )
		printf("\n%d --> %d = %d\n", src, i, dist[i] );
}
	
