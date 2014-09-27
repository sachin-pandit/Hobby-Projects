/*
    Experiment No: 6                                        
    USN:2BV07IS405
    Date: 22-09-08

	Program to find minimum cost spanning tree of a given undirected graph using kruskal's Algorithm...
*/


#include<stdio.h>
#include<stdlib.h>

int parent[10],min,ne=1,mincost=0;
int cost[10][10];
int i,j,a,b,u,v,n;

int main()
{
	printf("Enter the no. of vertices\n");
	scanf("%d",&n);
	printf("Enter the matrix for a graph\n");
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	  {
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
		   cost[i][j]=999;
	  }
	  while(ne<n)
	  {
		for(i=1,min=999;i<=n;i++)
		   for(j=1;j<=n;j++)
			if(cost[i][j]<min)
			{
				min=cost[i][j];
				a=u=i;
				b=v=j;
			}
			while(parent[u])
			   u=parent[u];
			while(parent[v])
			   v=parent[v];
			if(u!=v)
			{
				printf("\n%d\tedge\t(%d,%d)=%d",ne++,a,b,min);
				mincost+=min;
				parent[v]=u;
			}
			cost[a][b]=cost[b][a]=999;
           }
           printf("\n mincost=%d\n",mincost);
}


/*
             OUTPUT
--------------------------------

Enter the no. of vertices
4
Enter the matrix for a graph
0 9 7 1 
9 0 3 8
7 3 0 4
1 8 4 0\

1       edge    (14)=1
2       edge    (23)=3
3       edge    (34)=4
 mincost=8
[5thsem@ise103 ~]$ ./a.out
Enter the no. of vertices
4
Enter the matrix for a graph
0 2 1 3
2 0 999 8
1 999 0 4
3 8 4 0

1       edge    (13)=1
2       edge    (12)=2
3       edge    (14)=3
 mincost=6

*/
