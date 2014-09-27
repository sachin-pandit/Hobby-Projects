/*11. a. Implement Horspool algorithm for String Matching.

ALGORITHM: horspool(text[0…n-1],pattern[0….m-1])
//Implements Horspool’s algorithm for string matching
//Input: text string text[0….n-1] and pattern string pattern[0….m-1]
//Output: returns 1 if search is successful otherwise 0 is returned
nstrlen(text)
mstrlen(pattern)
for i0 to n-1 do
     shift[text[i]]m
end for
for j0 to m-2 do
     shift[pattern[j]]m-1-j
end for
for im-1 to n-1 insteps of i+shift[text[i]] do
     j0
     while pattern[m-1-j]=text[i-j] and j<=m-1 do
              jj+1
     end while
     if j=m
        return 1
     end if
end for
return 0
*/

//PROGRAM:


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int horspool(char[],char[]);
void main()
{
	 char text[300],pattern[20];
	 int ans;
	 system("clear");

	 printf("\nenter the text:\n");
	 scanf("%s",text);

	 printf("\nenter the pattern:\n");
	 scanf("%s",pattern);

	 ans=horspool(text,pattern);

	 if(ans==1)
		  printf("\npattern found\n");

	 else
		  printf("\npattern is not found\n");

}

int horspool(char text[],char pattern[])
{
	 int i,j,m,n,shift[300];
	 n=strlen(text);
	 m=strlen(pattern);
	 for(i=0;i<=n-1;i++)
		  shift[text[i]]=m;

	 for(j=0;j<=m-2;j++)
		  shift[pattern[j]]=m-1-j;

	 for(i=m-1;i<=n-1;i=i+shift[text[i]])
	 {
		  j=0;
		  while(pattern[m-1-j]==text[i-j]&&j<=m-1)
			   ++j;

		  if(j==m)
		  {
			   return 1;
			   exit(0);
  		  }
 	}
 return 0;
}

/*                                        ==========Output=============
Enter the text:
 jim_saw_me_in_the_barbershop

Enter the pattern:
 barber

Pattern found

Enter the text:
 jim_saw_me_in_the_barbershop

Enter the pattern:
 bab

Pattern is not found
*/
