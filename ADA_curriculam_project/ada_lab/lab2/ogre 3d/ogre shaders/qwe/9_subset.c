/*
    Experiment No: 9                                     
    USN:2BV07IS405
    Date: 13-10-08

	Program to find a subset of a given set s={s1,s2,....sn} of n +ve integers whose sum is equal to a given +ve integer d.A suitable message is to be displayed if the given problem instance doesn't have a solution... 
*/ 

#include<stdio.h>

void subset(int n,int d,int w[])
{
	int s,k,i,x[10],flag=0;
	for(i=1;i<=n;i++)
	    x[i]=0;
	s=0;
	k=1;
	x[k]=1;
	while(1)
	{
		if(k<=n && x[k]==1)
		{
			if(s+w[k]==d)
			{
				flag=1;
				printf("Solution is....\n");
				for(i=1;i<=n;i++)
				{
					if(x[i]==1)
						printf("%d ",w[i]);
				}
				printf("\n");
				x[k]=0;
			}
			else if(s+w[k]<d)
			{
				s=s+w[k];
			}
			else
				x[k]=0;
		}
		else
		{
			k--;
			while(k>0 && x[k]==0)
			{
				k--;
			}
			if(k==0)
				break;
			x[k]=0;
			s=s-w[k];
		}
		k=k+1;
		x[k]=1;
	}
	if(flag==0)
	{
		printf("No Solution....\n");
	}
}

int main()
{
	int n,i,d,w[10];
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	printf("Enter the %d elements in ascending order\n",n);
	for(i=1;i<=n;i++)
 	{
		scanf("%d",&w[i]);
	}
	printf("Enter the sum of set elements\n");
	scanf("%d",&d);
	subset(n,d,w);
	return 0;
}	

/*
		OUTPUT
-------------------------------------------
Enter the no. of elements
5
Enter the 5 elements in ascending order
1
2
5
6
8
Enter the sum of set elements
9
Solution is....
1 2 6 
Solution is....
1 8 

----------------------------------

Enter the no. of elements
1
Enter the 1 elements in ascending order
2
Enter the sum of set elements
5
No Solution....

*/
