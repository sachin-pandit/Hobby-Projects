
			/*			This package comes with ABSOLUTELY NO WARRANTY
					and can be distributed or shared among your freinds freely
					without subjecting to any modification, or  with modification
					under different authorization. The author holds no responsibilty
					of the outcome of the resource and its correctness. 			*/
					
					

HOW IT WORKS & SOME CONSTRAINTS :

	"resultView" is a java program to display the result using JTable . It uses swing, libraries of JTable and I/O stream

	"resultView.java" takes the input from a text file, you can change the text file if you want, 
	but the program works only for well defined pattern found in that text file. 
	you can copy paste the content from a PDF in that text file, 
	but you have to edit it manually ( the PDF_EXTRACTER is temporarily not available , i am  working on it & sorry for the inconvinience  ).
	so its upto you to place the right contents in the right text file.
	
	information about the sources used is found in the java program itself.


STEPS TO BE FOLLOWED TO RUN THE PROGRAM ( IN LINUX ENVIRONMENT ):
	
   IF JAVA IS ALREADY INSTALLED :
	1) Download the zip file(result), extract that to a folder of your choice.
	2) run a shell script "runMEAfterGiving755Permission.sh" after giving executable permission,
	   HOW TO GIVE EXECUTABLE PERMISSION TO A SHELL SCRIPT :
   		1) Open the Terminal
   		2) Go to the folder "result" by using change directory(cd). Example "cd /home/sachin/result" in my computer 
   		3) type "chmod 755 runMeAfterGiving755Permission.sh" ( without quotes ofcourse ;) )
   	3) run the script by typing ./runMeAfterGiving755Permission.sh
   	 
   IF JAVA NOT INSTALLED :
	
	1) open the terminal
	2) type "sudo apt-get install openjdk-6-jdk" (without quotes) and press enter, it will take few minutes to download and install
	3) goto STEP (1) of IF JAVA IS ALREADY INSTALLED
	

FEATURES OF THIS PROGRAM
	1) You can sort the data just by clicking on the header of the JTable
	2) Sort works for GPA and for all Subject, except the Roll.NO ( as it takes data in the form of a string )
	3) You can actually know who is the topper of the class ( except if he/she is a 10 pointer ) , 
				 	and topper in each subject .


CONTENTS OF THE FOLDER "resultContainer " 
	1) README.txt -> just a few information and instruction about the program
	2) run.bat -> Only for WINDOWS users, run this file to see the output
	3) runMeAfterGiving755Permission.sh -> Only for LINUX users , run this file to see the output
	4) sem3.txt -> A text file which contains 3rd sem(2011) result of CS B
	5) sem4.txt -> A text file which contains 4th sem(2011) result of CS B
	6) Folder "result" -> contains the java program
	7) Some snap shots of the program.
	
	
ps : my apologies to all if the displayed result is incorrect,and it may show error and warning
     in some system( if database is not upto date ) . i'll try to fix it if possible .
 
     and change the header of the table,i have included the subject of 4th sem in the header...
     i will update that as soon as we get the 5th sem results...










