/*   
    Experiment No : 12                                   
    USN:2BV07IS405
    Date: 10-11-08

           Program to compute transitive closure of the given directed graph using Warshall's 
   Algorithm...
*/



#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m[20][20],t[20][20],i,j,n,k;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the adjucency matrix\n");
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	scanf("%d",&m[i][j]);

	for(k=0;k<n;k++)
	{
	   for(i=0;i<n;i++)
	      {
		for(j=0;j<n;j++)
		{
		   t[i][j]=((m[i][j])||(m[i][k]&&m[k][j]));
		}
	      }
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
		m[i][j]=t[i][j];
	}

	printf("Transitive closure is------\n");
	for(i=0;i<n;i++)
	{
	   for(j=0;j<n;j++)
	     {
		printf("%d\t",m[i][j]);
	     }
	printf("\n");
	}

return 0;
}
	


/*			
	      OUTPUT
-------------------------------------

Enter the number of vertices
4
Enter the adjucency matrix
0 1 0 0
0 0 0 1
0 0 0 0
1 0 1 0
Transitive closure is------
1       1       1       1
1       1       1       1
0       0       0       0
1       1       1       1


*/
