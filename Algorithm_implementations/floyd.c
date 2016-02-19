/*
    Experiment No: 4                                 
    USN:2BV07IS405
    Date: 08-09-08

	Program to implement all pair shortest paths problem using Floyd's algorithm...
*/

#include<stdio.h>
#include<stdlib.h>

int a[5][5],n,i,j,k;
 
void floyds()
{
	for(k=1;k<=n;k++)
	  for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
	      
		if(a[i][k]+a[k][j]<a[i][j])
		   
		a[i][j]=a[i][k]+a[k][j];
}


int main()
{
	printf("enter the size of the graph\n");
	scanf("%d",&n);
	printf("Enter the graph data\n");
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	{
	  scanf("%d",&a[i][j]);
	  if(a[i][j]==0)
	     a[i][j]=999;
	}

	floyds();
	
	printf("the all pair shortest path \n");
	 for(i=1;i<=n;++i)
	{
	  for(j=1;j<=n;++j)
	  printf("\t%d",a[i][j]);
	  printf("\n");
	}
	return 0;
}


/*

	       OUTPUT
--------------------------------------

enter the size of the graph
4
Enter the graph data
0 2 1 3
0 0 0 4
0 0 0 2
0 0 0 0
the all pair shortest path 
        999     2       1       3
        999     999     999     4
        999     999     999     2
        999     999     999     999

*/
