/*
    Experiment No : 13(b)                           
    USN:2BV07IS405
    Date: 17-10-08

            Program to find Binomial Co-efficient using Dynamic Programming...

*/

#include<stdio.h>
#include<stdlib.h>


int min(int i,int k)
{
	if(i<k)
		return i;
	else
		return k;
}

int main()
{
	int i,n,k,j,c[10][10];
	printf("Enter the values of n and k of c(n,k)\n");
	scanf("%d%d",&n,&k);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=min(i,k);j++)
		{
		if(j==0||j==i)
			c[i][j]=1;
		else
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	printf("\nThe value of c(%d,%d)=%d\n",n,k,c[n][k]);
}


/*
	     OUTPUT
-----------------------------------

Enter the values of n and k of c(n,k)
6
2

The value of c(6,2)=15

*/
