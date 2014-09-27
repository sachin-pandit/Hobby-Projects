/* 
   Experiment No:3(b)                               
   USN:2BV07IS405
   Date: 01-09-08

	Program to check whether a given is connected or not using DFS method...
*/

#include<stdlib.h>
#include<stdio.h>
int label[15],a[25][25],n;

void dfs(int v)
{
int i,j;
label[v]=1;
for(i=v;i<=n;i++)
if(a[v][i]==1 && label[i]!=1)
dfs(i);
}


int main()
{


int i,j,flag;
printf("Enter the number of vertices\n");
scanf("%d",&n);
printf("Enter the  adjacency matrix elements\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
for(i=1;i<=n;i++)
label[i]=0;
dfs(1);
flag=1;

for(i=1;i<=n;i++)
if(label[i]==0)
{
flag=0;
break;
}

if(flag==1)
printf("The graph is connected\n");
else
printf("The graph is not connected\n");
}


/*
	       OUTPUT
-------------------------------------
Enter the number of vertices
3
Enter the  adjacency matrix elements
1 0 1
1 1 1
0 0 0
The graph is not connected

*/

