/*9   b. Check whether a given graph is connected or not using DFS method.  

ALGORITHM : dfs(a[1….n,1….n],src)
// Implements a depth-first traversal of a given digraph
//Input: An adjacency matrix a[1….n,1….n] of given digraph
//           src-from where the traversal is initiated
//Output: returns 0 if graph is not connected otherwise 1 is returned
vis[src]1
for j1 to n do
     if a[src,j]=1 and vis[j]!=1
         dfs(j)
     end if
end for
for j1 to n do
     if vis[j]!=1
           write ‘graph is not connected’
     end if
end for
write ‘graph is connected’
return
*/

//PROGRAM:
#include<stdio.h>
#include<stdlib.h>
int a[10][10],n,vis[10];
int dfs(int);

void main()
{
	 int i,j,src,ans;
	 system("clear");
	
	 for(j=1;j<=n;j++)
		  vis[j]=0;

	 printf("\nenter the no of nodes:\t");
	 scanf("%d",&n);
	 printf("\nenter the adjacency matrix:\n");

	 for(i=1;i<=n;i++)
		  for(j=1;j<=n;j++)
			   scanf("%d",&a[i][j]);

	 printf("\nenter the source node:\t");
	 scanf("%d",&src);
	 ans=dfs(src);

	 if(ans==1)
		  printf("\ngraph is connected\n");

	 else
		  printf("\ngragh is not connected\n");
}

int dfs(int src)
{
	 int j;
	 vis[src]=1;

	 for(j=1;j<=n;j++)
		  if(a[src][j]==1&&vis[j]!=1)
			   dfs(j);

	 for(j=1;j<=n;j++)
		  if(vis[j]!=1)
			   return 0;
	 return 1;
}


/*                                        ==========Output=============
Enter the no. of nodes:  4

Enter the adjacency matrix:
0   1   1   0
0   0   0   0
0   0   0   1
0   1   0   0

Enter the source node:  1

Graph is connected


Enter the no. of nodes:  4

Enter the adjacency matrix:
0   1   1   0
0   0   0   0
0   1   0   0
0   0   0   0

Enter the source node:  1

Graph is not connected
*/
