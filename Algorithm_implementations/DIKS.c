#include<stdio.h>
#include<stdlib.h>
int c[10][10],n,src;
void diks();

main()
{
	int i,j;
	system("clear");
	printf("enter the number of vertices\n");
	scanf("%d",&n);
	printf("enter the cost matrix\n");

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&c[i][j]);

	printf("enter src\n");
	scanf("%d",&src);
	diks();
}

void diks()
{
	int vis[10],dis[10],min,u,j,count;

	for(j=1;j<=n;j++)
		dis[j]=c[src][j];

	for(j=1;j<=n;j++)
		vis[j]=0;

	dis[src]=0;
	vis[src]=1;
	count=1;

	while(count!=n)
	{
		min=9999;
		for(j=1;j<=n;j++)
		{
			if(dis[j]<min && vis[j]!=1)
			{
				min=dis[j];
				u=j;
			}
		}
		vis[u]=1;
		count++;

		for(j=1;j<=n;j++)
			if(min+c[u][j]<dis[j]  && vis[j]!=1)
				dis[j]=min+c[u][j];

	}

	printf("the shortest distance is :\n");
	for(j=1;j<=n;j++)
		printf("\n %d -------> %d =%d\n",src,j,dis[j]);

}


