/*
   Experiment No:1                                  
   USN:2BV07IS405
   Date:11-08-08

	Program to implement N Queen's problem using Back Tracking...
*/

#include<stdlib.h>
#include<stdio.h>

int main()
{
	int n;
	printf("enter the number of queens");
	scanf("%d",&n);
	if(n==2||n==3)
	{
		printf("no solution");
		exit(0);
	}
	nqueen(n);
	return 0;
}

void nqueen(int n)
{
	int x[10];
	int count=0;
	int k=1;
	x[k]=0;
	while(k!=0)
	{
		x[k]=x[k]+1;
		while(x[k]<=n && !place(x,k))
		x[k]=x[k]+1;
		if(x[k]<=n)
		{
			if(k==n)
			{
				count++;
				printf("solution %d is......\n",count);
				print_soln(n,x);
			}
			else
			{
				k++;
				x[k]=0;
			}
		}
		else 
		k--;
	}
}

int place (int x[],int k)
{
	int i;
	for(i=1;i<k;i++)
	{
		if(x[i]==x[k]||i-x[i]==k-x[k]||i+x[i]==k+x[k])
		return 0;
	}
	return 1;
}

void print_soln(int n,int x[])
{
	int c[10][10];
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			c[i][j]=0;
	for(i=1;i<=n;i++)
		c[i][x[i]]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("  %d",c[i][j]);
		}
		printf("\n");
	}
}


/*

             OUTPUT
-----------------------------------


enter the number of queens
4
solution 1 is......
  0  1  0  0
  0  0  0  1
  1  0  0  0
  0  0  1  0
solution 2 is......
  0  0  1  0
  1  0  0  0
  0  0  0  1
  0  1  0  0

*/
