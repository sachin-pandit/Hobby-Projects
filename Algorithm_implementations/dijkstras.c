/*
    Experiment No: 5                                         
    USN:2BV07IS405
    Date: 15-09-08

	Program to find shortestpaths to other vertices using Dijkstra's algorithm with a given vertex in a weighted connected graph...
*/

#include<stdio.h>
#include<stdlib.h>


void dijkstras(int n,int cost[10][10],int source,int d[],int p[])
{
	int i,j,u,v,min;
	int s[10];

	for(i=0;i<n;i++)
	{
	      d[i]=cost[source][i];
	      s[i]=0;
	      p[i]=source;
	}
	
	s[source]=1;
	for(i=1;i<n;i++)
	{
	      min=9999;
	      u=-1;
	      for(j=0;j<n;j++)
	      {
		if(s[j]==0)
		{
		  if(d[j]<min)
		  {
		    min=d[j];
		    u=j;
		  }
		}
	     }
	     if(u==-1)
		return;
		s[u]=1;
		for(v=0;v<n;v++)
		{
		    if(s[v]==0)
		    {
			if(d[u]+cost[u][v]<d[v])
			{
			  d[v]=d[u]+cost[u][v];
			  p[v]=u;
			}
		   }		
	  	}
	 }

}

void print(int d[],int p[],int n,int source)
{
	int i,dest;
	for(dest=0;dest<n;dest++)
	{
	   i=dest;
	    if(d[i]==999)
		printf("%d not reachable\n");
	        else
		{
		  while(i!=source)
		   {
			printf("%d<-",i);
			i=p[i];
		   }
		printf("%d=%d\n",i,d[dest]);
	       }
       }
}


int main()
{
	int n,i,j,cost[10][10],source,d[10],p[10];
	printf("Enter the no of vertices\n");
	scanf("%d",&n);
	printf("Enter the weighted matrix\n");
	for(i=0;i<n;i++)

	for(j=0;j<n;j++)
	{
		scanf("%d",&cost[i][j]);
	}
	
	printf("enter source vertex\n");
	scanf("%d",&source);
        dijkstras(n,cost,source,d,p);
	printf("shortest path from source vertex\n");
	  print(d,p,n,source);
        return;
}



/*
		OUTPUT
---------------------------------------

Enter the no of vertices
4 
Enter the weighted matrix
0  2  4  5
3  0 999 4
3  4  0  65  
9  4  5  0
enter source vertex
0
shortest path from source vertex
0=0
1<-0=2
2<-0=4
3<-0=5

*/

