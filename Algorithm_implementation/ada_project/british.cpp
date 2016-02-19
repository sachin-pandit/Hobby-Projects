# include <stdio.h>
# include <iostream>
# include <stdlib.h>
using namespace std;

#define BLUE    		"\033[22;34m"
#define MAGENTA  		"\033[22;35m"
#define CYAN  			"\033[22;30m"
#define GREY  			"\033[22;37m"
#define GREEN 			"\033[22;32m"
#define YELLOW  		"\033[22;33m"
#define LIGHT_CYAN  	"\033[22;36m"
#define WHITE  			"\033[22;37m"
#define DARK_BROWN  	"\033[22;31m"

#define BACK_BROWN  		"\033[22;41m"
#define BACK_GREEN  		"\033[22;42m"
#define BACK_LIGHT_BROWN  	"\033[22;43m"
#define BACK_BLUE  			"\033[22;44m"
#define BACK_PINK  			"\033[22;45m"
#define BACK_LIGHT_BLUE  	"\033[22;46m"
#define BACK_GREY  			"\033[22;47m"

#define RESET_COLOR "\e[m"
#define MAKE_GREEN "\e[32m"
#define WIN 1
#define LOST 0





void flag_display(int *a)
{
  cout<<"___________________________________________"<<endl;
      cout<<"|  "<<a[0]<<" |-._         :|  "<<a[1]<<" |:         _.-|  "<<a[2]<<" |"<<endl;
      cout<<"|____|-._`-._     :|____|:     _.-'_.-|____|"<<endl;
      cout<<"|    |-._`-._`-._ :|    |: _.-'_.-'_.-|    |"<<endl;
      cout<<"|    |   `-._`-._`:|    |:`_.-'_.-'   |    |"<<endl;
      cout<<"|----|-------------|----|-------------|----|"<<endl;
      cout<<"|  "<<a[3]<<" |             |  "<<a[4]<<" |             |  "<<a[5]<<" |"<<endl;
      cout<<"|____|_____________|____|_____________|____|"<<endl;
      cout<<"|    |    _.--_.--:|    |:--._--._    |    |"<<endl;
      cout<<"|____|_.-'_.-'_.-':|____|:`-._`-._`-._|____|"<<endl;
      cout<<"|    |'.-'_.-'    :|    |:    `-._`-._|    |"<<endl;
      cout<<"|  "<<a[6]<<" | .-'        :|  "<<a[7]<<" |:        `-._|  "<<a[8]<<" |"<<endl;
      cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  /*cout<<" _______________________________________________	"<<endl;
  cout<<"|	"<<a[0]<<"	|	"<<a[1]<<"	|	"<<a[2]<<"	|"<<endl;
  cout<<" _______________________________________________	"<<endl;
  cout<<"|	"<<a[3]<<"	|	"<<a[4]<<"	|	"<<a[5]<<"	|"<<endl;
  cout<<" _______________________________________________	"<<endl;
  cout<<"|	"<<a[6]<<"	|	"<<a[7]<<"	|	"<<a[8]<<"	|"<<endl<<endl;
  cout<<endl;*/
  return;
}
void pos()
{
  int a[9];
  cout<<"\n\n\t\tPOSITIONS DISPLAY\n";
  for(int i=0;i<9;i++)
	 a[i]=i;
  flag_display(a);
  return;
}

void end(int x)
{
  if(x==1)
	 {
		cout<<"\nCONGRATULATIONS\n";
		cout<<"YOU WIN\n";
		exit(0);
	 }
  else
	 cout<<"\n YOU LOOSE \n";
	 cout<<"\n\t\tTHANK YOU\n\n";
	 exit(0);	
}

void win(int *a,int x)
{
  if(a[0]==x&&((a[4]==x&&a[8]==x)||(a[1]==x&&a[2]==x)||(a[3]==x&&a[6]==x)))
	 end(x);
  if(a[4]==x&&((a[1]==x&&a[7]==x)||(a[2]==x&&a[6]==x)||(a[3]==x&&a[5]==x)))
	 end(x);
  if(a[8]==x&&((a[2]==x&&a[5]==x)||(a[6]==x&&a[7]==x)))
	 end(x);
  return;
}
void ffor(int *a)
{
	if(a[4]==1)
		 {
			if(a[0]==1)
		a[8]=2;
			else if(a[8]==1)
		{
			if(a[0]==0)
				a[0]=2;
			else
				goto m1;
		}
			else if(a[1]==1)
		a[7]=2;
			else if(a[7]==1)
		a[1]=2;
			else if(a[3]==1)
		a[5]=2;
			else if(a[5]==1)
		a[3]=2;
			else if(a[2]==1)
		a[6]=2;
			else
		a[2]=2;
		 }
	  else if(a[0]==1)
		 {
			if(a[1]==1)
		a[2]=2;
			else if(a[2]==1)
		a[1]=2;
			else if(a[6]==1)
		a[3]=2;
			else if(a[3]==1)
		a[6]=2;
			else
		a[1]=2;

		 }
	  else if(a[8]==1)
		 {
			if(a[6]==1)
		a[7]=2;
			else if(a[7]==1)
		a[6]=2;
			else if(a[2]==1)
		a[5]=2;
			else if(a[5]==1)
		a[2]=2;
			else if(a[1]==0)
		a[1]=2;
			else
		a[3]=2;
		 }
	  else if(a[2]==1)
		 {
	      if(a[5]==1)
		a[8]=2;
	      else if(a[8]==1)
		a[5]=2;
	      else if(a[1]==1)
		a[2]=2;
	      else if(a[2]==1)
		a[1]=2;
			else if(a[3]==0)
		a[3]=2;
			else
		a[1]=2;

		 }
	  else if(a[6]==1)
		 {
			if(a[3]==1)
			{
				if(a[0]==0)
					a[0]=2;
				else
					goto m1;
			}
			else if(a[0]==1)
		a[3]=2;
			else if(a[7]==1)
		a[8]=2;
			else if(a[8]==1)
		a[7]=2;
			else if(a[1]==0)
		a[1]=2;
			else
		a[3]=2;
		 }
		return;
		m1:for(int j=1;j<8;j+=2)
		 {
				if(a[j]==0)
			{
			  a[j]=2;
			  j=8;
			}
	    }


}

void sfor(int *a)
{
	if(a[4]==2)
		 {
			if(a[0]==2 && a[8]!=1)
		a[8]=2;
			else if(a[8]==2 && a[0]!=1)
		a[0]=2;
			else if(a[1]==2 && a[7]!=1)
		a[7]=2;
			else if(a[7]==2 && a[1]!=1)
		a[1]=2;
			else if(a[3]==2 && a[5]!=1)
		a[5]=2;
			else if(a[5]==2 && a[8]!=1)
		a[3]=2;
			else if(a[2]==2 && a[6]!=1)
		a[6]=2;
			else if(a[6]==2 && a[2]!=1)
		a[2]=2;
		else
			 goto m;

		 }
	  else if(a[0]==2)
		 {
			if(a[1]==2 && a[2]!=1)
		a[2]=2;
			else if(a[2]==2 && a[1]!=1)
		a[1]=2;
			else if(a[6]==2 && a[3]!=1)
		a[3]=2;
			else if(a[3]==2 && a[6]!=1)
		a[6]=2;
		else
			 goto m;

		 }
	  else if(a[8]==2)
		 {
			if(a[6]==2 && a[7]!=1)
		a[7]=2;
			else if(a[7]==2 && a[6]!=1)
		a[6]=2;
			else if(a[2]==2 && a[5]!=1)
		a[5]=2;
			else if(a[5]==2 && a[2]!=1)
		a[2]=2;
		else
			 goto m;

		 }

	  else if(a[2]==2)
		 {
			if(a[5]==2 && a[8]!=1)
		a[8]=2;
			else if(a[8]==2 && a[5]!=1)
		a[5]=2;
			else if(a[1]==2 && a[2]!=1)
		a[2]=2;
			else if(a[2]==1 && a[1]!=1)
		a[1]=2;
		else
			 goto m;

		 }
	  else if(a[6]==2)
		 {
			if(a[3]==2 && a[0]!=1)
		a[0]=2;
			else if(a[0]==2 && a[3]!=1)
		a[3]=2;
			else if(a[7]==2 && a[8]!=1)
		a[8]=2;
			else if(a[8]==2 && a[7]!=1)
		a[7]=2;
		else
			 goto m;

		 }

	  else
		 {
  m:			if(a[4]==1)
		{
		  if(a[0]==1 && (a[1]==1 || a[3]==1))
			 {
				if(a[8]==0)
			a[8]=2;
				else
			goto m1;
			 }

		  else if(a[1]==1 && (a[6]==1 || a[8]==1) )
			 {
				if(a[7]==0)
			a[7]=2;
				else if(a[6]==1 && a[2]==0)
			a[2]=2;
				else 
			goto m1;
			 }
  else if(a[2]==1 && (a[3]==1 || a[7]==1))
			 {
				if(a[6]==0)
			a[6]=2;
				else if(a[3]==1 && a[5]==0)
			a[5]=2;
				else
			goto m1;
			 }

else if(a[3]==1 && (a[0]==1 || a[1]==1))
			 {
				if(a[5]==0)
			a[5]=2;
				else
			goto m1;
			 }
  else if(a[5]==1 && (a[0]==1 || a[6]==1))
			 {
				if(a[3]==0)
			a[3]=2;
				else
			goto m1;
			 }

  else if(a[6]==1 && (a[1]==1 || a[5]==1))
		 {
				if(a[2]==0)
			a[2]=2;
				else
			goto m1;
			  }
		  else if(a[7]==1 && (a[0]==1 || a[2]==1))
			 {
				if(a[1]==0)
			a[1]=2;
				else
			goto m1;
			 }
			 else if(a[8]==1 && (a[1]==1 || a[3]==1))
			 {
				if(a[0]==0)
			a[0]=2;
				else
			goto m1;
			 }

		  else
			 goto m1;
		}


	else if(a[0]==1)
		{
		  if(a[1]==1 && (a[4]==1 || a[5]==1))
			 {
				if(a[2]==0)
			a[2]=2;
				else
			goto m1;

			 }
		  else if(a[2]==1 && (a[3]==1 || a[4]==1 || a[5]==1))
			 {
				if(a[1]==0)
			a[1]=2;
				else
			goto m1;

			 }

		  else if(a[3]==1 && (a[4]==1 || a[7]==1))
			 {
				if(a[6]==0)
			a[6]=2;
				else
			goto m1;

			 }
		  else if(a[4]==1 && (a[5]==1 || a[7]==1))
			 {
				if(a[8]==0)
			a[8]=1;
				else
			goto m1;
			 }
	 else if(a[6]==1 && a[4]==1)
			 {
				if(a[3]==0)
			a[3]=2;
				else
			goto m1;

			 }

		  else
			 goto m1;
		}

		else if(a[8]==1)
		{
			  if(a[0]==1)
			 {
				if(a[4]==0)
			a[4]=2;
				else
			goto m1;
			 }
		  else if(a[2]==1 && a[4]==1)
			 {
				if(a[5]==1)
			a[5]=2;
				else
			goto m1;
			 }

			 else if(a[4]==1 && (a[4]==1 || a[3]==1))
			 {
				if(a[0]==0)
			a[0]=2;
				else
			goto m1;
			 }
			else if(a[5]==1 && (a[1]==1 || a[4]==1))
			 {
				if(a[2]==0)
			a[2]=2;
				else
			goto m1;
			 }
			else if(a[6]==1 && (a[3]==1||a[4]==1||a[5]==1))
			 {
				if(a[7]==0)
			a[7]=2;
				else
			goto m1;
			 }
		  else if(a[7]==1 && (a[3]==1 || a[4]==1))
			 {
				if(a[6]==0)
			a[6]=2;
				else
			goto m1;
			 }
		  else
			 goto m1;
		}

		else if(a[2]==1)
		{
		 if(a[0]==1 && (a[3]==1 || a[4]==1 || a[5]==1))
			 {	if(a[1]==0)
			a[1]=2;
				else
			goto m1;
			 }
  else if(a[1]==1 && (a[3]==1 || a[4]==1))
			 {	if(a[0]==0)
			a[0]=2;
				else
			goto m1;
			 }


		  else if(a[4]==1 && (a[3]==1 || a[3]==7))
			 {
				if(a[6]==0)
			a[6]=1;
				else
			goto m1;
			 }
		  else  if(a[5]==1 && (a[4]==1 || a[7]==1))
			 {
				if(a[8]==0)
			a[8]=2;
				else
			goto m1;
			 }
else if(a[6]==1)
			 {
				if(a[4]==0)
			a[4]=1;
				else
			goto m1;
			 }
  else if(a[8]==1 && (a[1]==1||a[4]==1||a[7]==1))
			 {	if(a[5]==0)
			a[5]=2;
				else
			goto m1;
			 }

		  else
			 goto m1;
		}



			else if(a[6]==1)
		{
		  if(a[0]==1 && (a[1]==1 || a[4]==1 || a[7]==1))
			 {
				if(a[3]==0)
			a[3]=2;
				else
			goto m1;
			 }
  else if(a[2]==1)
			 {
				if(a[4]==0)
			a[4]==2;
				else
			goto m1;
			 }
else  if(a[3]==1 && (a[1]==1 || a[4]==1))
			 {
				if(a[0]==0)
			a[0]=2;
				else
			goto m1;
			 }
  else if(a[4]==1 && (a[1]==1 || a[5]==1))






			 {
				if(a[2]==0)
			a[2]=2;
				else
			goto m1;
			 }


		  else if(a[7]==1 && (a[4]==1 || a[5]==1))
			 {
				if(a[8]==0)
			a[8]=2;
				else
			goto m1;
			 }

else if(a[8]==1 && (a[3]==1 || a[4]==1 || a[5]==1))
			 {
				if(a[7]==0)
			a[7]=2;
				else
			goto m1;
			 }


		  else
			 goto m1;
		}
		else
		{
		m1:for(int j=1;j<8;j+=2)
			 {
				if(a[j]==0)
			{
			  a[j]=2;
			  j=8;
			}
		    }
		}			
	    }
}

void fwfor(int *a)
{
	if(a[4]==2)
	{
		if(a[0]==2 && a[8]==0)
		{
			if(a[5]==2)
			{
				a[8]=2;
				a[5]=0;
			}
			else if(a[7]==2)
			{
				a[7]=0;
				a[8]=2;
			}
			else
				goto k;
		}
		else if(a[8]==2 && a[0]==0)
		{
			if(a[1]==2)
			{
				a[0]=2;
				a[1]=0;
			}
			else if(a[3]==2)
			{
				a[0]=2;
				a[3]=0;
			}
			else
				goto k;
		}
		else if(a[1]==2 && a[7]==0)
		{
			if(a[8]==2)
			{
				a[7]=2;
				a[8]=0;
			}
			else if(a[6]==2)
			{
				a[7]=2;
				a[6]=0;
			}
			else
				goto k;
		}
		else if(a[7]==2 && a[1]==0)
		{
			if(a[0]==2)
			{
				a[1]=2;
				a[0]=0;
			}
			else if(a[2]==2)
			{
				a[1]=2;
				a[2]=0;
			}
			else 
				goto k;
		}
		else if(a[3]==2 && a[5]==0)
		{
			if(a[2]==2)
			{
				a[5]=2;
				a[2]=0;
			}
			else if(a[8]==2)
			{
				a[5]=2;
				a[8]=0;
			}
			else 
				goto k;
		}
		else if(a[5]==2 && a[3]==0)
		{
			if(a[0]==2)
			{
				a[3]=2;
				a[0]=0;
			}
			else if(a[6]==2)
			{
				a[3]=2;
				a[6]=0;
			}
			else 
				goto k;
		}
		else if(a[2]==2 && a[6]==0)
		{
			if(a[3]==2)
			{
				a[6]=2;
				a[3]=0;
			}
			else if(a[7]==2)
			{
				a[6]=2;
				a[7]=0;
			}
			else 
				goto k;
		}
		else if(a[6]==2 && a[2]==0)
		{
			if(a[1]==2)
			{
				a[2]=2;
				a[1]=0;
			}
			else if(a[5]==2)
			{
				a[2]=2;
				a[5]=0;
			}
			else 
				goto k;
		}
		else
			 goto k;

	  }
	  else if(a[0]==2)
	  {
		if(a[1]==2 && a[2]==0)
		{
			if(a[4]==2)
			{
				a[2]=2;
				a[4]=0;
			}
			else if(a[5]==2)
			{
				a[2]=2;
				a[5]=0;
			}
			else 
				goto k;
		}
		else if(a[2]==2 && a[1]==0)
		{
			if(a[4]==2)
			{
				a[1]=2;
				a[4]=0;
			}
			else 
				goto k;
		}
		else if(a[6]==2 && a[3]==0)
		{
			if(a[4]==2)
			{
				a[3]=2;
				a[4]=0;
			}
			else 
				goto k;
		}
		else if(a[3]==2 && a[6]==0)
		{
			if(a[4]==2)
			{
				a[6]=2;
				a[4]=0;
			}
			else if(a[7]==2)
			{
				a[6]=2;
				a[7]=0;
			}
			else 
				goto k;
		}
		else if(a[4]==2 && a[8]==0)
		{
			if(a[5]==2)
			{
				a[8]=2;
				a[5]=0;
			}
			else if(a[7]==2)
			{
				a[8]=2;
				a[7]=0;
			}
			else 
				goto k;
		}
		else if(a[8]==2 && a[4]==0)
		{
			a[4]=2;
			if(a[1]==2)
				a[1]=0;
			else if(a[2]==2)
				a[2]=0;
			else if(a[3]==2)
				a[3]=0;
			else if(a[5]==2)
				a[5]=0;
			else if(a[6]==2)
				a[6]=0;
			else if(a[7]==2)
				a[7]=0;				
		}
		else
			 goto k;

	 }
	 else if(a[8]==2)
	{
		if(a[6]==2 && a[7]==0)
		{
			if(a[3]==2)
			{
				a[7]=2;
				a[3]=0;
			}
			else if(a[4]==2)
			{
				a[7]=2;
				a[4]=0;
			}
			else if(a[5]==2)
			{
				a[7]=2;
				a[5]=0;
			}
			else 
				goto k;
		}
		else if(a[7]==2 && a[6]==0)
		{
			if(a[3]==2)
			{
				a[6]=2;
				a[3]=0;
			}
			else if(a[4]==2)
			{
				a[6]=2;
				a[4]=0;
			}
			else 
				goto k;
		}
		else if(a[2]==2 && a[5]==0)
		{
			if(a[1]==2)
			{
				a[5]=2;
				a[1]=0;
			}
			else if(a[4]==2)
			{
				a[5]=2;
				a[4]=0;
			}
			else if(a[7]==2)
			{
				a[5]=2;
				a[7]=0;
			}
			else 
				goto k;
		}
		else if(a[5]==2 && a[2]==0)
		{
			if(a[1]==2)
			{
				a[2]=2;
				a[1]=0;
			}
			else if(a[4]==2)
			{
				a[2]=2;
				a[4]=0;
			}
			else 
				goto k;
		}
		else if(a[0]==2 && a[4]==0)
		{
			a[4]=2;
			if(a[1]==2)
				a[1]=0;
			else if(a[2]==2)
				a[2]=0;
			else if(a[3]==2)
				a[3]=0;
			else if(a[5]==2)
				a[5]=0;
			else if(a[6]==2)
				a[6]=0;
			else if(a[7]==2)
				a[7]=0;				
		}
		else
			 goto k;

	}

	else if(a[2]==2)
	{
		if(a[5]==2 && a[8]==0)
		{
			if(a[7]==2)
			{
				a[8]=2;
				a[7]=0;
			}
			else if(a[4]==2)
			{
				a[8]=2;
				a[4]=0;
			}
			else 
				goto k;
		}
		else if(a[8]==2 && a[5]==0)
		{
			if(a[1]==2)
			{
				a[4]=2;
				a[1]=0;
			}
			else if(a[4]==2)
			{
				a[5]=2;
				a[4]=0;
			}
			else if(a[7]==2)
			{
				a[5]=2;
				a[7]=0;
			}
			else 
				goto k;
		}
		else if(a[1]==2 && a[0]==0)
		{
			if(a[3]==2)
			{
				a[0]=2;
				a[3]=0;
			}
			else if(a[4]==2)
			{
				a[0]=2;
				a[4]=0;
			}
			else 
				goto k;
		}
		else if(a[0]==1 && a[1]==0)
		{
			if(a[3]==2)
			{
				a[1]=2;
				a[3]=0;
			}
			else if(a[4]==2)
			{
				a[1]=2;
				a[4]=0;
			}
			else if(a[5]==2)
			{
				a[1]=2;
				a[5]=0;
			}
			else 
				goto k;
		}
		else if(a[6]==2 && a[4]==0)
		{
			a[4]=2;
			if(a[1]==2)
				a[1]=0;
			else if(a[2]==2)
				a[2]=0;
			else if(a[3]==2)
				a[3]=0;
			else if(a[5]==2)
				a[5]=0;
			else if(a[6]==2)
				a[6]=0;
			else if(a[7]==2)
				a[7]=0;				
		}
		else
			 goto k;

	}
	else if(a[6]==2)
	{
		if(a[3]==2 && a[0]==0)
		{
			if(a[1]==2)
			{
				a[0]=2;
				a[1]=0;
			}
			else if(a[4]==2)
			{
				a[0]=2;
				a[4]=0;
			}
			else 
				goto k;
		}
		else if(a[0]==2 && a[3]==0)
		{
			if(a[1]==2)
			{
				a[3]=2;
				a[1]=0;
			}
			else if(a[4]==2)
			{
				a[3]=2;
				a[4]=0;
			}
			else if(a[7]==2)
			{
				a[3]=2;
				a[7]=0;
			}
			else 
				goto k;
		}
		else if(a[7]==2 && a[8]==0)
		{
			if(a[4]==2)
			{
				a[8]=2;
				a[4]=0;
			}
			else if(a[5]==2)
			{
				a[8]=2;
				a[5]=0;
			}
			else 
				goto k;
		}
		else if(a[8]==2 && a[7]==0)
		{
			if(a[3]==2)
			{
				a[7]=2;
				a[3]=0;
			}
			else if(a[4]==2)
			{
				a[7]=2;
				a[4]=0;
			}
			else if(a[5]==2)
			{
				a[7]=2;
				a[5]=0;
			}
			else 
				goto k;
		}
		else if(a[2]==2 && a[4]==0)
		{
			a[4]=2;
			if(a[1]==2)
				a[1]=0;
			else if(a[2]==2)
				a[2]=0;
			else if(a[3]==2)
				a[3]=0;
			else if(a[5]==2)
				a[5]=0;
			else if(a[6]==2)
				a[6]=0;
			else if(a[7]==2)
				a[7]=0;				
		}
		else
			 goto k;

	}//win comp end

	else
	{
  k:		if(a[4]==1)
		{
		  	if(a[0]==1)
		  	{
		  		if(a[5]==1 && a[7]==2 && a[8]==0)
		  		{
		  			a[8]=2;
		  			a[7]=0;
		  		}
		  		else if(a[7]==1 && a[5]==2 && a[8]==0)
		  		{
		  			a[8]=2;
		  			a[5]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}
		  	else if(a[1]==1)
		  	{
		  		if(a[6]==1 && a[8]==2 && a[7]==0)
		  		{
		  			a[7]=2;
		  			a[8]=0;
		  		}
		  		else if(a[8]==1 && a[6]==2 && a[7]==0)
		  		{
		  			a[7]=2;
		  			a[6]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}
		  	else if(a[2]==1)
		  	{
		  		if(a[3]==1 && a[7]==2 && a[6]==0)
		  		{
		  			a[6]=2;
		  			a[7]=0;
		  		}
		  		else if(a[7]==1 && a[3]==2 && a[6]==0)
		  		{
		  			a[6]=2;
		  			a[3]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}
		  	else if(a[3]==1)
		  	{
		  		if(a[2]==1 && a[8]==2 && a[5]==0)
		  		{
		  			a[5]=2;
		  			a[8]=0;
		  		}
		  		else if(a[8]==1 && a[2]==2 && a[5]==0)
		  		{
		  			a[5]=2;
		  			a[2]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}		
		  	else if(a[5]==1)
		  	{
		  		if(a[0]==1 && a[6]==2 && a[3]==0)
		  		{
		  			a[3]=2;
		  			a[6]=0;
		  		}
		  		else if(a[6]==1 && a[0]==2 && a[3]==0)
		  		{
		  			a[3]=2;
		  			a[0]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}
		  	else if(a[6]==1)
		  	{
		  		if(a[5]==1 && a[1]==2 && a[2]==0)
		  		{
		  			a[2]=2;
		  			a[1]=0;
		  		}
		  		else if(a[1]==1 && a[5]==2 && a[2]==0)
		  		{
		  			a[2]=2;
		  			a[5]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}
		  	else if(a[7]==1)
		  	{
		  		if(a[0]==1 && a[2]==2 && a[1]==0)
		  		{
		  			a[1]=2;
		  			a[2]=0;
		  		}
		  		else if(a[2]==1 && a[0]==2 && a[1]==0)
		  		{
		  			a[1]=2;
		  			a[0]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}
		  	else if(a[8]==1)
		  	{
		  		if(a[1]==1 && a[3]==2 && a[0]==0)
		  		{
		  			a[0]=2;
		  			a[3]=0;
		  		}
		  		else if(a[3]==1 && a[1]==2 && a[0]==0)
		  		{
		  			a[0]=2;
		  			a[1]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}
			else
				 goto m2;
		}


		else if(a[0]==1)
		{
			if(a[1]==1)
		  	{
		  		if(a[5]==1 && a[4]==2 && a[2]==0)
		  		{
		  			a[2]=2;
		  			a[4]=0;
		  		}
		  		else if(a[7]==1 && a[5]==2 && a[8]==0)
		  		{
		  			a[2]=2;
		  			a[5]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}
		  	else if(a[2]==1)
		  	{
		  		goto m2;
		  	
		  	}
		  	else if(a[6]==1)
		  	{
		  		goto m2;
		  	
		  	}
		  	else if(a[3]==1)
		  	{
		  		if(a[4]==1 && a[7]==2 && a[6]==0)
		  		{
		  			a[6]=2;
		  			a[7]=0;
		  		}
		  		else if(a[7]==1 && a[4]==2 && a[6]==0)
		  		{
		  			a[6]=2;
		  			a[4]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}		
		  	else if(a[8]==1)
		  	{
		  		a[4]=2;
				if(a[1]==2)
					a[1]=0;
				else if(a[2]==2)
					a[2]=0;
				else if(a[3]==2)
					a[3]=0;
				else if(a[5]==2)
					a[5]=0;
				else if(a[6]==2)
					a[6]=0;
				else if(a[7]==2)
					a[7]=0;		  		
		  		
		  	}
		  	else if(a[4]==1)
		  	{
		  		if(a[5]==1 && a[7]==2 && a[8]==0)
		  		{
		  			a[8]=2;
		  			a[7]=0;
		  		}
		  		else if(a[7]==1 && a[5]==2 && a[8]==0)
		  		{
		  			a[8]=2;
		  			a[5]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}
		  	else
				 goto m2;
		}

		
		
		else if(a[8]==1)
		{
			if(a[2]==1)
		  	{
		  		goto m2;
		  	}
		  	else if(a[5]==1)
		  	{
		  		if(a[4]==1 && a[1]==2 && a[2]==0)
		  		{
		  			a[2]=2;
		  			a[1]=0;
		  		}
		  		else if(a[1]==1 && a[4]==2 && a[2]==0)
		  		{
		  			a[2]=2;
		  			a[4]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}		
		  	else if(a[0]==1)
		  	{
		  		a[4]=2;
				if(a[1]==2)
					a[1]=0;
				else if(a[2]==2)
					a[2]=0;
				else if(a[3]==2)
					a[3]=0;
				else if(a[5]==2)
					a[5]=0;
				else if(a[6]==2)
					a[6]=0;
				else if(a[7]==2)
					a[7]=0;		  		
		  		
		  	}
		  	else if(a[4]==1)
		  	{
		  		if(a[1]==1 && a[3]==2 && a[0]==0)
		  		{
		  			a[0]=2;
		  			a[3]=0;
		  		}
		  		else if(a[3]==1 && a[1]==2 && a[0]==0)
		  		{
		  			a[0]=2;
		  			a[1]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}
		  	else if(a[7]==1)
		  	{
		  		if(a[4]==1 && a[3]==2 && a[6]==0)
		  		{
		  			a[6]=2;
		  			a[3]=0;
		  		}
		  		else if(a[3]==1 && a[4]==2 && a[6]==0)
		  		{
		  			a[6]=2;
		  			a[4]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}
		  	else if(a[6]==1)
		  	{
		  		goto m2;
		  	
		  	}
		  	
		  	else
				 goto m2;
		
		
		}	
		
		
		
		else if(a[2]==1)
		{
		 	if(a[1]==1)
		  	{
		  		if(a[3]==1 && a[4]==2 && a[0]==0)
		  		{
		  			a[0]=2;
		  			a[4]=0;
		  		}
		  		else if(a[4]==1 && a[3]==2 && a[0]==0)
		  		{
		  			a[0]=2;
		  			a[3]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}
		  	else if(a[0]==1)
		  	{
		  		goto m2;
		  	
		  	}
		  	else if(a[8]==1)
		  	{
		  		goto m2;
		  	
		  	}
		  	else if(a[5]==1)
		  	{
		  		if(a[4]==1 && a[7]==2 && a[8]==0)
		  		{
		  			a[8]=2;
		  			a[7]=0;
		  		}
		  		else if(a[7]==1 && a[4]==2 && a[8]==0)
		  		{
		  			a[8]=2;
		  			a[4]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}		
		  	else if(a[6]==1)
		  	{
		  		a[4]=2;
				if(a[1]==2)
					a[1]=0;
				else if(a[2]==2)
					a[2]=0;
				else if(a[3]==2)
					a[3]=0;
				else if(a[5]==2)
					a[5]=0;
				else if(a[6]==2)
					a[6]=0;
				else if(a[7]==2)
					a[7]=0;		  		
		  		
		  	}
		  	else if(a[4]==1)
		  	{
		  		if(a[3]==1 && a[7]==2 && a[6]==0)
		  		{
		  			a[6]=2;
		  			a[7]=0;
		  		}
		  		else if(a[7]==1 && a[3]==2 && a[6]==0)
		  		{
		  			a[6]=2;
		  			a[3]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}
		  	else
				 goto m2;
		 
		}

	
		
		
		else if(a[6]==1)
		{
		  if(a[3]==1)
		  	{
		  		if(a[1]==1 && a[4]==2 && a[0]==0)
		  		{
		  			a[0]=2;
		  			a[4]=0;
		  		}
		  		else if(a[4]==1 && a[1]==2 && a[0]==0)
		  		{
		  			a[0]=2;
		  			a[1]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}
		  	else if(a[0]==1)
		  	{
		  		goto m2;
		  	
		  	}
		  	else if(a[8]==1)
		  	{
		  		goto m2;
		  	
		  	}
		  	else if(a[7]==1)
		  	{
		  		if(a[4]==1 && a[5]==2 && a[8]==0)
		  		{
		  			a[8]=2;
		  			a[5]=0;
		  		}
		  		else if(a[5]==1 && a[4]==2 && a[8]==0)
		  		{
		  			a[8]=2;
		  			a[4]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}		
		  	else if(a[2]==1)
		  	{
		  		a[4]=2;
				if(a[1]==2)
					a[1]=0;
				else if(a[2]==2)
					a[2]=0;
				else if(a[3]==2)
					a[3]=0;
				else if(a[5]==2)
					a[5]=0;
				else if(a[6]==2)
					a[6]=0;
				else if(a[7]==2)
					a[7]=0;		  		
		  		
		  	}
		  	else if(a[4]==1)
		  	{
		  		if(a[5]==1 && a[1]==2 && a[2]==0)
		  		{
		  			a[2]=2;
		  			a[1]=0;
		  		}
		  		else if(a[1]==1 && a[5]==2 && a[2]==0)
		  		{
		  			a[2]=2;
		  			a[5]=0;
		  		}
		  		else
		  			goto m2;
		  	
		  	}
		  	else
				 goto m2;
		}
		
		else
		{
		
	m2:		if(a[4]==0)
				{
					for(int j=0;j<8;j++)
					{
						if(a[j]==2 && j!=4)
						{
							a[4]=2;
							a[j]=0;
							j=8;
							goto j;
						}
					}
				}
			if(a[1]==2)
				{
					if(a[0]==0)
					{
						a[0]=2;
						a[1]=0;
						goto j;
					}
					if(a[2]==0)
					{
						a[2]=2;
						a[1]=0;
						goto j;
					}
				}
			if(a[2]==2)
				{
					if(a[5]==0)
					{
						a[5]=2;
						a[2]=0;
						goto j;
					}
					if(a[1]==0)
					{
						a[2]=0;
						a[1]=2;
						goto j;
					}
				}
			if(a[3]==2)
				{
					if(a[0]==0)
					{
						a[0]=2;
						a[3]=0;
						goto j;
					}
					if(a[6]==0)
					{	
						a[6]=2;
						a[3]=0;
						goto j;
					}
				}
			if(a[5]==2)
				{
					if(a[2]==0)
					{
						a[2]=2;
						a[5]=0;
						goto j;
					}
					if(a[8]==0)
					{
						a[8]=2;
						a[5]=0;
						goto j;
					}
				}
			if(a[6]==2)
			{
				if(a[7]==0)
				{
					a[7]=2;
					a[6]=0;
					goto j;
				}
				if(a[3]==0)
				{
					a[3]=2;
					a[6]=0;				
					goto j;
				}
			}	
			if(a[7]==2)
			{
				if(a[6]==0)
				{
					a[6]=2;
					a[7]=0;
					goto j;
				}
				if(a[8]==0)
				{
					a[8]=2;
					a[7]=0;
					goto j;
				}					
			}
			if(a[8]==2)
			{
				if(a[5]==0)
				{
					a[5]=2;
					a[8]=0;
					goto j;
				}
				if(a[7]==0)
				{
					a[7]=2;
					a[8]=0;
					goto j;
				}
			}
			if(a[4]==2)
			{
				int k;
				for(k==0;k<8;k++)
				{
					if(a[k]==0)
					{
						a[4]=0;
						a[k]=2;
						k=8;
					}
				}
			}						
			
		}			
  	j:cout<<" ";
  }//block player 1 end






}//fwfor end


int main()
{
  int a[9],temp,i;
  system("clear");
  system("gimp flag.jpg");
  pos();
  cout<<"\n\n\t\t     START GAME\n";
  for(i=0;i<9;i++)
	 a[i]=0;
  flag_display(a);
  for(i=0;i<3;i++)
	 {
	 l:	cout<<"\nEnter the position of insertion:";
		cin>>temp;
		if(temp<0||temp>8)
	{
	  cout<<"\nOOPS ! ! ! INVALID PLACEMENT :: POSITION DOESN't EXISTS\n";
	  goto l;
	}
		if(a[temp]!=0 || a[temp]==2)
	{
	  cout<<"\nOOPS ! ! ! INVALID PLACEMENT :: PAWN ALREADY EXISTS\n";
	  goto l;
	}
		a[temp]=1;

		/*	COMPUTER's ARENA	*/

		if(i==0)
	{
	  if(a[4]!=1)
		 a[4]=2;
	  else
		 a[0]=2;
	}
		else if(i==1)
	{
	  ffor(a);

	}
	else
	{
		sfor(a);		 
	}
	flag_display(a);
    }//for end
  win(a,1);
  win(a,2);
	
	while(1)
	{
		int s,d;
	x:	cout<<"ENTER POSITION WHERE PAWN TO BE PLACED:";
		cin>>d;
		cout<<"\nENTER POSITION FROM WHERE PAWN TO BE DRAGGED:"; 				
		cin>>s;
		if(d<0 || d>8 || s<0 || s>8)
		{
			cout<<"\nOOPS ! ! ! INVALID PLACEMENT :: POSITION DOESN't EXISTS\n";
			goto x;		
		}
		else if(a[d]!=0)
		{
			cout<<"\nOOPS ! ! ! INVALID PLACEMENT :: PAWN ALREADY EXISTS\n";
			goto x;		
		}
		else if(a[s]==0 || a[s]==2)
		{
			cout<<(MAGENTA"\nOOPS ! ! ! INVALID SOURCE :: PAWN DOESN'T EXISTS\n"RESET_COLOR);
			goto x;	
		}			
		else 
		{
			if(d==0 && (s==1 || s==3 || s==4))
			{
				a[d]=1;
				a[s]=0;
			}
			else if(d==1 && (s==0 || s==4 || s==2))
			{
				a[d]=1;
				a[s]=0;
			}
			else if(d==2 && (s==1 || s==4 || s==5))
			{
				a[d]=1;
				a[s]=0;
			}
		    else if(d==3 && (s==0 || s==4 || s==6))
			{
				a[d]=1;
				a[s]=0;				
			}
			else if(d==4)
			{
				a[d]=1;
				a[s]=0;
			}
			else if(d==5 && (s==2 || s==4 || s==8))
			{
				a[d]=1;
				a[s]=0;
			}
			else if(d==6 && (s==3 || s==4 || s==7))
			{
				a[d]=1;
				a[s]=0;			
			}
			else if(d==7 && (s==6 || s==4 || s==8))
			{
				a[d]=1;
				a[s]=0;			
			}
			else if(d==8 && (s==4 || s==5 || s==7))
			{
				a[d]=1;
				a[s]=0;
			}
			win(a,1);
			win(a,2);
		}
	   
	/*	COMPUTER's ARENA	*/
			
		fwfor(a);

 	   flag_display(a);






	}//while end	
  return 0;
}//main end

