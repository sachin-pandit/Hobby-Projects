/*
      Experiment No: 7                                       
      USN:2BV07IS405
      Date: 26-09-08

	Program to sort a given set of elements using the Heapsort method and determine the time required to sort the elements.Repeat the experiment for different values of n,the number of elements in the list to be sorted and plot a graph of the time taken versus n...  
 
*/

#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void heap_bottom_up(int,int a[]);
void heapsort(int,int a[]);

void heap_bottom_up(int n,int a[])
{
	int i,j,p,k,v,heap;
	p=n/2;
	for(i=p;i>0;i--)
	{
		heap=0;
		k=i;
		v=a[k];
		while(!heap&&((2*k)<=n))
		{
			j=2*k;
			if(j<n)
			{
				if(a[j]<a[j+1])
					j=j+1;
			}
			if(v>=a[j])
				heap=1;
			else
			{
				a[k]=a[j];
				k=j;
			}
		}
		a[k]=v;
	}
}

void heapsort(int n,int a[])
{
	int i,temp;
	heap_bottom_up(n,a);
	for(i=n;i>1;i--)
	{
		temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		heap_bottom_up(i-1,a);
	}
}

int main()
{
	int i,n,n1,a[20000];
	clock_t start, end;
	double duration;
	int ch1,ch2;
	clrscr();
	printf("\n----------MENU----------\n");
	printf("1-DEMO SORTING\n");
	printf("2-RECORD TIME\n");
	printf("3-EXIT\n");
	printf("------------------------\n");

	printf("ENTER THE TASK\n");
	scanf("%d", &ch1);

	switch(ch1)
	{
		case 1: printf("\n ENTER THE SIZE\n");
			scanf("%d",&n);

			printf("ENTER ARRAY ELEMENTS\n\n");
			for(i=1;i<=n;i++)
				scanf("%d", &a[i]);
			heapsort(n,a);

			printf("SORTED ARRAY  IS\n");
			for(i=1;i<=n;i++)
				printf("%d\n",a[i]);
			break;

		case 2: printf("ENTER N (RANGING FROM 1000 to 20000))\n");
			scanf("%d", &n);

			n1=n;

			printf("ENTER ARRAY FORMAT\n");
			printf("\n----------SUB MENU----------\n");
			printf("1-ASCENDING ORDER ARRAY\n");
			printf("2-DESCENDING ORDER ARRAY\n");
			printf("3-RANDOM ORDRERD ARRAY\n");
			printf("----------------------------\n");

			printf("ENTER YOUR CHOICE\n");
			scanf("%d", &ch2);

			switch(ch2)
			{
				case 1: for(i=1;i<=n;i++)
						a[i]=i;
					break;

				case 2:
					for(i=1;i<=n;i++)
					{
						a[i]=n1;
						n1--;
					}
					break;

				case 3:	for(i=1;i<=n;i++)
						a[i]= rand() % n +1;
					break;

			}

			printf("DONE!!\n");

			/* THIS SNIPPET PRINTS THE GENERATED RANDOM ARRAY.
			UNCOMMENT AND EXECUTE TO SEE THE SAME.
			printf("THE ARRAY IS...\n");
			for(i=1;i<=n;i++)
				printf("%d\t",a[i]);
			*/

			start=clock();
			heapsort(n,a);
			end=clock();

			duration= end-start;
			duration= duration / CLOCKS_PER_SEC;


			printf("\n\n\nTIME REQUIRED TO SORT IS..%g seconds\n", duration);

			break;

		case 3: printf("EXIT!!");
			break;

	}
	getch();
	return 0;
}

/* 
              OUTPUT
------------------------------------


----------MENU----------
1-DEMO SORTING
2-RECORD TIME
3-EXIT
------------------------
ENTER THE TASK
1

 ENTER THE SIZE
5
ENTER ARRAY ELEMENTS

23
45
68
1
2
SORTED ARRAY  IS
1
2
23
45
68




----------MENU----------
1-DEMO SORTING
2-RECORD TIME
3-EXIT
------------------------
ENTER THE TASK
2
ENTER N (RANGING FROM 1000 to 20000))
15000
ENTER ARRAY FORMAT

----------SUB MENU----------
1-ASCENDING ORDER ARRAY
2-DESCENDING ORDER ARRAY
3-RANDOM ORDRERD ARRAY
----------------------------
ENTER YOUR CHOICE
1
DONE!!



TIME REQUIRED TO SORT IS..1.724 seconds

*/
