/*
   Experiment No:2(b)                                             
   USN:2BV07IS405
   Date:18-08-08
 
	Program to implement Recursive Binary Search and Linear Search and determine the time required to search an element.Repeat the experiment for different values of n,the number of elements in the list to be searched and plot a graph of the time taken versus n...  

*/

#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

void selection_sort(int *a,int n)
{

	int i,j,min,temp;

	for(i=0;i<=n-2;i++)
	{
		min=i;
		for(j=i+1;j<=n-1;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}

int binary_search(int *a,int key,int low,int high)
{
	int mid;

	if(low>high)
		return -1;

	mid=(low+high)/2;

	if(a[mid]==key)
		return mid;
	else if (key>a[mid])
		return (binary_search(a,key,mid+1,high));
	else if(key<a[mid])
		return (binary_search(a,key,low,mid-1));

}


int linear_search(int *a,int key,int n)
{
	if(n<0)
		return -1;
	else if(key==a[n])
		return n;
	else
		return(linear_search(a,key,(n-1)));
}



int main()
{
	int i,n,a[20000],key,loc;
	clock_t start, end;
	double duration;
	int ch1,ch2,ch3,ch4;
       clrscr();
	printf("\n----------MENU----------\n");
	printf("1-DEMO SORTING\n");
	printf("2-RECORD TIME\n");
	printf("3-EXIT\n");
	printf("------------------------\n");

	printf(" THE TASK\n");
	scanf("%d", &ch1);

	switch(ch1)
	{
case 1:

	printf("\n1->linear\n2->binary\n3->exit\n");
	printf("enter your choice\n");
	scanf("%d",&ch2);
	switch(ch2)
	{
	case 1:
		printf("enter the array size\n");
		scanf("%d",&n);
		printf("enter the array elements\n");
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("enter the element to be searched\n");
		scanf("%d",&key);
		loc=linear_search(a,key,n-1);
		if(loc<0)
			printf("not found\n");
		else
			printf("found\n");

		break;


	case 2:

		printf("enter the array size\n");
		scanf("%d",&n);
		printf("enter the array elements\n");
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		selection_sort(a,n);
		printf("enter the element to be searched\n");
		scanf("%d",&key);
		loc=binary_search(a,key,0,n-1);
		if(loc<0)
			printf("not found\n");
		else
			printf("found\n");

		break;

	default:exit(0);
	 }
	break;
case 2: printf("ENTER N (RANGING FROM 1000 to 20000))\n");
			scanf("%d", &n);
			for(i=0;i<n;i++)
				a[i]=i+1;
	printf("\n1->linear\n2->binary\n3->exit\n");
	printf("enter your choice\n");
	scanf("%d",&ch3);
	switch(ch3)
	{
	case 1:   printf("\n enter the key element\n");
		      scanf("%d",&key);
			 start=clock();
		loc=linear_search(a,key,n-1);
			end=clock();
		if(loc<0)
			printf("not found\n");
		else
			printf("found\n");

		  break;
      case 2:    printf("\n enter the key element\n");
		      scanf("%d",&key);
			start=clock();
			loc=binary_search(a,key,0,n-1);
			end=clock();
		if(loc<0)
			printf("not found\n");
		else
			printf("found\n");

		  break;
	default: exit(0);
      }

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
-------------------------------


----------MENU----------
1-DEMO SORTING
2-RECORD TIME
3-EXIT
------------------------
 THE TASK
1

1->linear
2->binary
3->exit
enter your choice
1
enter the array size
4
enter the array elements
34
56
78
90
enter the element to be searched
78
found



----------MENU----------
1-DEMO SORTING
2-RECORD TIME
3-EXIT
------------------------
 THE TASK
1

1->linear
2->binary
3->exit
enter your choice
2
enter the array size
4
enter the array elements
34
67
89
12
enter the element to be searched
12
found




----------MENU----------
1-DEMO SORTING
2-RECORD TIME
3-EXIT
------------------------
 THE TASK
2
ENTER N (RANGING FROM 1000 to 20000))
20000

1->linear
2->binary
3->exit
enter your choice
1

 enter the key element
31000
not found



TIME REQUIRED TO SORT IS..0.001 seconds




----------MENU----------
1-DEMO SORTING
2-RECORD TIME
3-EXIT
------------------------
 THE TASK
2
ENTER N (RANGING FROM 1000 to 20000))
20000

1->linear
2->binary
3->exit
enter your choice
2

 enter the key element
31000
not found

TIME REQUIRED TO SORT IS..0 seconds

*/










