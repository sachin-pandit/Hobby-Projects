/*
    Experiment No : 11(a)                                  
    USN:2BV07IS405
    Date : 03-11-08

            Program to sort a given set of elements using Merge Sort method and determine the time required to sort the elements...

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int[],int[],int,int,int);
                                                      
void ms(int a[],int b[],int low,int high)
{
	int i,mid;
	if(low<high)
	{
		mid=(low+high)/2;
		ms(a,b,low,mid);
		ms(a,b,mid+1,high);
		merge(a,b,low,mid,high);
		for(i=low;i<=high;i++)
			a[i]=b[i];
	}
	return;
}

void merge(int a[],int b[],int low,int mid,int high)
{
	int i,j,k;
	i=low;
	k=low;
	j=mid+1;
	while(i<=mid && j<=high)
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	
	if(i>mid)
		while(j<=high)
			b[k++]=a[j++];
	else
		if(j>high)	
		while(i<=mid)
			b[k++]=a[i++];
}

int main()
{
	int i,n,n1,a[20000],b[20000];
	clock_t start, end;
	double duration;
	int ch1,ch2;

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
			for(i=0;i<n;i++)
				scanf("%d", &a[i]);
			 ms(a,b,0,n-1);


			printf("SORTED ARRAY  IS\n");
			for(i=0;i<n;i++)
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
				case 1: for(i=0;i<n;i++)
						a[i]=i+1;
					break;

				case 2:
					for(i=0;i<n;i++)
					{
						a[i]=n1;
						n1--;
					}
					break;

				case 3:	for(i=0;i<n;i++)
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
			 ms(a,b,0,n-1);
			end=clock();

			duration= end-start;
			duration= duration / CLOCKS_PER_SEC;


			printf("\n\n\nTIME REQUIRED TO SORT IS..%g seconds\n", duration);

			break;

		case 3: printf("EXIT!!");
			break;

	}
  
	return 0;
}


/*
            OUTPUT
-------------------------------

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

45
89
6
52
32
SORTED ARRAY  IS
6
32
45
52
89





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
2
DONE!!



TIME REQUIRED TO SORT IS..0 seconds

*/
