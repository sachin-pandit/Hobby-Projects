/*13. b. Compute the transitive closure of a given directed graph using Warshall’s algorithm.

ALGORITHM: warshalls(a[1…n,1….n])
// Implements Warshall’s algorithm for computing the transitive closure
//Input: The adjacency matrix a[1….n,1….n] of a digraph with n vertices
//Output: The transitive closure of the digraph
for k1 to n do
    for i1 to n do
        for j1 to n do
            if a[i,j]!=1
                if a[i,k]=1 and a[k,j]=1
                     a[i,j]1
                end if
            end if
        end for
    end for
end for
write ‘ path matrix is’
for i1 to n do
    for j1 to n do
        write a[i,j]
    end for
end for

PROGRAM:
*/

#include<stdio.h>
#include<stdlib.h>
int a[10][10],n;

void warshalls();

void main()
{
	 int i,j;
	 system("clear");
	 printf("\nenter the no. of vertices:\t");
	 scanf("%d",&n);

	 printf("\nenter the adjacency matrix:\n");
	 for(i=1;i<=n;i++)
		  for(j=1;j<=n;j++)
			   scanf("%d",&a[i][j]);
	 warshalls();
}

void warshalls()
{
	 int i,j,k;
	 for(k=1;k<=n;k++)
	 {
		  for(i=1;i<=n;i++)
		  {
			   for(j=1;j<=n;j++)
			   {
				    if(a[i][j]!=1)
				    {
					     if(a[i][k]==1&&a[k][j]==1)
						      a[i][j]=1;
				    }
			   }
		  }
	 }
 	printf("\npath matrix is:\n");

	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n;j++)
			   printf("%d\t",a[i][j]);
		  printf("\n\n");
	 }
}

/*                                        ==========Output=============
Enter the no. of vertices:  4

Enter the adjacency matrix:
0   1   0   0
0   0   1   0
1   0   0   1
0   0   0   0

Path matrix is:
1   1   1   1
1   1   1   1
1   1   1   1
0   0   0   0
*/
