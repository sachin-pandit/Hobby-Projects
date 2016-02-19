/*11.  b. Find the Binomial Co-efficient using Dynamic programming.

ALGORITHM: bincof(n,r)
//computes binomial co-efficient c(n,r) by dynamic programming
//Input: Non-negative integers n and r such that n>=r>=0
//Output: The value of  c(n,r)
for i0 to n do
    for j0 to r do
        if j=0
           c[i,j]1
        else if i=j
           c[i,j]1
         else if i>j
           c[i,j]c[i-1,j]+c[i-1,j-1]
         end if
     end for
end for
write ‘optimal solution is’,c[n,r]

PROGRAM:
*/

#include<stdio.h>
#include<stdlib.h>
void bincof(int,int);
void main()
{
	 int n,r;
	 system("clear");
	 printf("\nenter n:\t");
	 scanf("%d",&n);
	 printf("\nenter r:\t");
	 scanf("%d",&r);
	 bincof(n,r);
}

void bincof(int n,int r)
{
	 int i,j,c[10][10];
	 for(i=0;i<=n;i++)
	 {
		  for(j=0;j<=n;j++)
		  {
			   if(j==0)
				    c[i][j]=1;

			   else if(i==j)
				    c[i][j]=1;

			   else if(i>j)
				    c[i][j]=c[i-1][j]+c[i-1][j-1];
			   else if( j > i )
			   	    c[i][j]=0;
			   	  
		
		  }
	 }

	 printf("\noutput is:\n");
	 for(i=0;i<=n;i++)
	 {
		  for(j=0;j<=n;j++)
			   if(j<=i)
				    printf("%d\t",c[i][j]);
		  printf("\n\n");
	 }

	 printf("\noptimal solution is %d\n",c[n][r]);
}

/*                                        ==========Output=============
Enter  n:  4

Enter  r:   2

Output is:
1
1   1
1   2   1
1   3   3
1   4   6

Optimal solution is  6
*/
