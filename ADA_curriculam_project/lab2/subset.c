/*10. Find a subset of a given set S = {s1,s2,……,sn} of n positive integers whose sum is equal to a given positive integer d. For example, if S = {1,2,5,6,8} and d = 9 there are two solutions {1,2,6} and {1,8}. A suitable message is to be displayed if the given problem instance doesn’t have a solution.

ALGORITHM: subset(s[1….n],d)
// To find subsets of a given set of n positive integers whose sum is equal to a given positive integer d
//Input: An array s[1….n] of sorted elements
//           d-required sum
//Output: subsets of given set s[1….n] whose elements sum is equal to d
x[k]1
if m+s[k]=d
   write ‘subset solution is’, countcount+1
   for i0 to k do
       if x[i]=1
          write s[i]
       end if
   end for
else if m+s[k]+s[k+1]<=d
       subset(m+s[k],k+1,sum-s[k])
end if
if m+sum-s[k]>=d and m+s[k+1]<=d
    x[k]0
    subset(m,k+1,sum-s[k])
end if 
 
PROGRAM:
*/

#include<stdio.h>
#include<stdlib.h>

void subset(int,int,int);
int count,d,s[10],x[10];

void main()
{
	 int sum=0,count=0,i,n;
	 system("clear");
	 printf("\nenter no. of elements:\t");
	 scanf("%d",&n);

	 printf("\nenter the elements in ascending order:\n");
	 for(i=0;i<=n-1;i++)
		  scanf("%d",&s[i]);

	 printf("\nenter the required sum:\t");
	 scanf("%d",&d);

	 for(i=0;i<=n-1;i++)
		  sum=sum+s[i];

	 if(sum<d||s[0]>d)
		  printf("no solution exists\n");

	 else
		  subset(0,0,sum); 
	
	 printf("\n");
}

void subset(int m,int k,int sum)
{
	 int i;
	 x[k]=1;
	 if(m+s[k]==d)
	 {
		  printf("\nsubset solution %d is\n",++count);
		  for(i=0;i<=k;i++)
			   if(x[i]==1)
				    printf("%d\t",s[i]);
	 }

	 else if(m+s[k]+s[k+1]<=d)
		  subset(m+s[k],k+1,sum-s[k]);

	 if((m+sum-s[k]>=d)&&(m+s[k+1]<=d))
	 {
		  x[k]=0;
		  subset(m,k+1,sum-s[k]);
	 }
}

/*                                        ==========Output=============
Enter the no. of elements:  5

Enter the elements in ascending order:
1    2    5    6    8

Enter the required sum:   9

Subset solution  1  is
1    2    6

Subset solution  2  is
1    8
*/
