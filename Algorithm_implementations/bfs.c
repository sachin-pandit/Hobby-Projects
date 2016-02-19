/* 
   Experiment No:3(a)                                          
   USN:2BV07IS405
   Date: 01-09-08

	Program to print all the nodes reachable from a given starting node in a digraph using BFS method...
*/

#include<stdio.h>
#include<stdlib.h>

void bfs(int);
void addtoqueue(int);
void removefromqueue();
int queue_empty();
int frontofqueue();

struct queue
{
	int elem[20];
	int front,rear;
}q;

int n,v[20],a[20][20],flag=0;


int main()
{
	int i,j,s;
	q.front=q.rear=0;
	printf("\nEnter the number of vertices\n");
	scanf("%d",&n);
	printf("\nEnter the graph in the form of adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	/*Initialize visit states of vertices to zero*/
	for(i=0;i<n;i++)
		v[i]=0;
		printf("\nEnter the start vertex number: ");
	scanf("%d",&s);	
	printf("\nThe Nodes reachable from %d are \n",s);
	bfs(s);
	if(flag==0)
		printf("\nNo Nodes are reachable from %d\n",s);
	printf("\n\n");
	return 0;
}

void bfs(int k)
{
	int m;
	v[k]=1;
	addtoqueue(k);
	while(!queue_empty())
	{
		k=frontofqueue();
		for(m=0;m<n;m++)
		{
			if((a[k][m]==1)&&(v[m]==0))
			{
				printf(" %d ",m);
				v[m]=1;
				flag=1;
				addtoqueue(m);
			}
		}
		removefromqueue();
	}
}

void addtoqueue(int x)
{
	q.elem[(q.rear++)]=x;
}

void removefromqueue()
{
	(q.front)++;
}

int queue_empty()
{
	if(q.front==q.rear)
		return 1;
	return 0;
}

int frontofqueue()
{
	return(q.elem[q.front]);
}



/* 
                    OUTPUT
----------------------------------------------
Enter the number of vertices
3

Enter the graph in the form of adjacency matrix
0 1 1
1 0 1
1 1 0

Enter the start vertex number: 1

The Nodes reachable from 1 are 
 0  2 

*/
