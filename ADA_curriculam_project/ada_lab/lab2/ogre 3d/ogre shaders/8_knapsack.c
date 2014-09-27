/*
	Program to implement 0/1 Knapsack problem using Dynamic programming...
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int weights[20],values[20],v[20][20],i,j,n,m,val1,val2,x[20]={0,0,0};
	
	printf("Enter the no. of items\n");
	scanf("%d",&n);
	printf("Enter the knapsack capacity\n");
	scanf("%d",&m);
	printf("Enter weights\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&weights[i]);
	}
	printf("Enter values(profit)\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&values[i]);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0||j==0)
				v[i][j]=0;
			else
				v[i][j]=-1;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(j<weights[i])
				v[i][j]=v[i-1][j];
			else
			{
				val1=values[i]+v[i-1][j-weights[i]];
				val2=v[i-1][j];
				if(val1>val2)
					v[i][j]=val1;
				else
					v[i][j]=val2;
			}
		}
	}
	printf("The matrix is.....\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("%d\t",v[i][j]);
		}
		printf("\n");
	}
	printf("Maximum profit obtained is...%d\n",v[n][m]);
	i=n;
	j=m;
	while(i!=0 && j!=0)
	{
		if(v[i][j]!=v[i-1][j])
		{
			x[i]=1;
			j=j-weights[i];
		}
		i=i-1;
	}
	printf("The items selected are....\n");
	for(i=0;i<=n;i++)
	{
		if(x[i]==1)
		{
			printf("%d\n",i);
		}
	}
	return 0;
}




/*
		OUTPUT
----------------------------------------
Enter the no. of items
4
Enter the knapsack capacity
5 
Enter weights
2
1
3
2
Enter values(profit)
12
10
20
15
The matrix is.....
0       0       0       0       0       0
0       0       12      12      12      12
0       10      12      22      22      22
0       10      12      22      30      32
0       10      15      25      30      37
Maximum profit obtained is...37
The items selected are....
1
2
4
*/ 
