/*
    Experiment No: 10                                    
    USN:2BV07IS405
    Date : 20-10-08

    Program to find minimum cost spanning tree of a given undirected graph using prim's algorithm... 
*/

#include<stdio.h>
#include<stdlib.h>
int a,b,u,v,n,i,j,ne=1,x,y,flag=0;
int visited[10],min,mincost=0,cost[10][10];

int main()
{
	printf("Enter the no. of vertices\n");
	scanf("%d",&n);
	printf("Enter the weight matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}

	for(x=1;x<=n;x++)
	{
		for(y=1;y<=n;y++)
		{
			if(cost[x][y]==999)
				flag++;
		}
		if(flag==n)
		{
			printf("disconnected\n");
			exit(0);
		}
	}

	for(i=2;i<=n;i++)
	{
		visited[i]=0;
	}
	printf("the edge of spanning tree are\n");
	visited[1]=1;
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					if(visited[i]==0)
						continue;
					else
					{
						min=cost[i][j];
						a=u=i;
						b=v=j;
					}
				}
			}
		}
		if(visited[u]||visited[v]==0)
		{
			printf("%d\tedge\t(%d->%d)=%d",ne++,a,b,min);
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
		printf("\nmincost=%d\n",mincost);
	}
	return 0;
}

/*

               OUTPUT
-------------------------------------
Enter the no. of vertices
5
Enter the weight matrix
0 0 3 6 0
0 0 0 1 0
3 0 0 0 2
6 1 0 0 9
0 0 2 9 0
the edge of spanning tree are
1       edge    (1->3)=3
mincost=3
2       edge    (3->5)=2
mincost=5
3       edge    (1->4)=6
mincost=11
4       edge    (4->2)=1
mincost=12

*/
