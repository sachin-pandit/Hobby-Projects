/*14. Implement N Queen’s problem using Back Tracking.

ALGORITHM: nqueens(n)
//places n queens on a nXn matrix such that no two queens are placed along  same row or same column
//or same diagonal using backtracking method
//Input: n-number of queens
//Output: k-the queen k
//             x[k]-the position of queen k
k1
x[k]0
while k!=0 do
       x[k]x[k]+1
       while place(x,k)!=1 and x[k]<=n do
                x[k]x[k]+1
       end while
       if x[k]<=n
           if k=n
              for k1 to n do
                    write k,x[k]
              end for
           else
              kk+1
              x[k]0
           end if
       else
            kk-1
       end if
end while

ALGORITHM: place(x[k],k)
//places n queens on a nXn matrix such that no two queens are placed along  same row or same column
//or same diagonal using backtracking method
//Input: k-the queen k
//           x[k]- position of queen k
//Output: returns 0 if any two queens are placed along same diagonal or same column otherwise 1 is returned
 for i1 to k-1 do
      if i-x[i]=k-x[k] or i+x[i]=k+x[k] or x[i]=x[k]
          return 0
      end if
end for
return 1   

PROGRAM:
*/

#include<stdio.h>
#include<stdlib.h>
void nqueens(int);
int place(int[],int);
void main()
{
	 int n;
	 system("clear");
	 printf("\nenter the no of queens:\t");
	 scanf("%d",&n);
	 nqueens(n);
}

void nqueens(int n)
{
	 int k,x[10],count=0;
	 k=1;
	 x[k]=0;
	 while(k!=0)
	 {
		  x[k]++;
		  while(place(x,k)!=1&&x[k]<=n)
		  {
			   x[k]++;
		  }
		  if(x[k]<=n)
		  {
			   if(k==n)
			   {
				    printf("\nsolution %d  is",++count);
				    for(k=1;k<=n;k++)
				    {
					     printf("\n%d----->%d\n\n",k,x[k]);
				    }
			   }
			   else
			   {
				    k++;
				    x[k]=0;
			   }
		  }
		  else
		  {
			   k--;
		  }
	 }
}

int place(int x[],int k)
{
 int i;
 for(i=1;i<=k-1;i++)
 {
	  if(i-k == x[i]-x[k]||i-k == x[k]-x[i]||x[i]==x[k])
	  {
		   return 0;
	  }
 }
 return 1;
}

/*                                        ==========Output=============
Enter the no. of queens:  4

Solution  1  is
1----------->2
2----------->4
3----------->1
4----------->3

Solution  2  is
1----------->3
2----------->1
3----------->4
4----------->2
*/
