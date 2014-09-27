/*
    Experiment No : 13(a)                            
    USN:2BV07IS405
    Date: 17-10-08

            Program to implement Horspool Algorithm for String Matching...

*/

#include<stdio.h>
#define max 256
#include<string.h>

int t[256];
int horspool(char scr[],char pat[]);

void shift(char pat[])
{
	int i,j,m;
	m=strlen(pat);
	for(i=0;i<max;i++)
		t[i]=m;

	for(j=0;j<m-1;j++)
	{
		t[pat[j]]=m-1-j;
	}
}

int horspool(char scr[],char pat[])
{
	int i,k,m,n;
	n=strlen(scr);
	m= strlen(pat);
	i=m-1;
	while(i<n)
	{
		k=0;
		while((k<n)&& pat[m-1-k]==scr[i-k])
			k++;
		if(k==m)
			return(i-m+1);
		else 
			i+=t[scr[i]];
	}
	return -1;
}

main()
{
	char scr[100],pat[100];
	int pos;
	printf("Enter the text : ");
	scanf("%[^\n]",scr);
	printf("Enter the pattern : ");
	scanf("%s",pat);

	shift(pat);
	pos=horspool(scr,pat);
	if(pos>=0)
		printf("\nThe pattern found at position %d\n",pos+1);
	else 
		printf("\nPattern not found\n");
	return 0;
}


/*
		 OUTPUT
---------------------------------------------

Enter the text : JIM_SAW_ME_IN_A_BARBERSHOP
Enter the pattern : BARBER

The pattern found at position 17
---------------------------------------------

Enter the text : JIM_SAW_ME_IN_A_BARBERSHOP
Enter the pattern : BVBCET

Pattern not found

*/

