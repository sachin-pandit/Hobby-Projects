/*9.   a. Print all the nodes reachable from a given starting node in a digraph using BFS method.

ALGORITHM : bfs(a[1….n,1….n],src)
// Implements a breadth-first traversal of a given digraph
//Input: An adjacency matrix a[1….n,1….n] of given digraph
//           src-from where the traversal is initiated
//Output: The digraph with its vertices marked with consecutive integers in the order they have been visited
//             by the BFS traversal mark each vertex in vis[1….n]  with 0 as mark of being “node is not reachable”
for j1 to n do
     vis[j]0
end for
f0
r-1
vis[src]1
rr+1
while f<=r do
      iq[f]
      ff+1
       for j1 to n do
            if a[i,j]=1 and vis[j]!=1
                 vis[j]1
                 rr+1
                 q[r]j
            end if
       end for
end while
for j1 to n do
    if vis[j]!=1
       write ‘node is not reachable’
    else
       write ‘node is reachable’
    end if
end for      
*/
              

//PROGRAM:

#include<stdio.h>
#include<stdlib.h>
int a[10][10],n;
void bfs(int);

void main()
{
	 int i,j,src;
	 system("clear");
	 printf("\nenter the no of nodes:\t");
	 scanf("%d",&n);
	 printf("\nenter the adjacency matrix:\n");
      
       	for(i=1;i<=n;i++)
  	  for(j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
	
	 printf("\nenter the source node:\t");
	 scanf("%d",&src);
	 bfs(src);

}

void bfs(int src)
{
 	int q[10],f=0,r=-1,vis[10],i,j;
	 for(j=1;j<=n;j++)
	  vis[j]=0;
	
	 vis[src]=1;
	 r=r+1;
	 q[r]=src;
	 while(f<=r)
	 {
		  i=q[f];
		  f=f+1;
  		  for(j=1;j<=n;j++)
		  {
		       if(a[i][j]==1&&vis[j]!=1)
			   {
			    vis[j]=1;
			    r=r+1;
			    q[r]=j;
   			   }
		  }
	}

	for(j=1;j<=n;j++)
 	{
 		if(vis[j]!=1)
   			printf("\nnode %d is not reachable\n",j);
		else
		        printf("\nnode %d is reachable\n",j);
        }
}

/*                                        ==========Output=============
Enter the no. of nodes:  6

Enter the adjacency matrix:
0   1   1   1   0   0
0   0   0   0   1   0
0   0   0   0   1   1
0   0   0   0   0   1
0   0   0   0   0   0
0   0   0   0   1   0

Enter the source node:  1

Node  1  is reachable
Node  2  is reachable
Node  3  is reachable
Node  4  is reachable
Node  5  is reachable
Node  6  is reachable
*/
