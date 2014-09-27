/*
	
  A JAVA program to display the result in the form of a table using JTable.
  This java program works only if it is fed with right input.

  Change the input file if you want, by typing the name or path of file in line number "67"  ( but plz make sure that format is correct, 
  for correct format refer "res4.txt" found in "resultContainer" folder  )	
*/



/* the folder in which the original java program is places */
package result;

/* some library files */
import javax.swing.*;
import java.awt.*;
import java.io.*;


public class resultView extends JPanel {
    private boolean DEBUG = false,fail = false;
    int i = 0 , j = 0, k = 0, integer;
    float gpa, credits = 0;
    public resultView() {
        super(new GridLayout(1,0));


/* Change the Header of JTable by editing the string found the columnNames array */
        try{
		String[] columnNames =  { "Roll.No", "USN1","USN2", "MATHS", "GT", "ADA", "DBMS", "OOPS" , "MP" , "OOPS LAB", "MP LAB", "credits", "GPA"};
		Object[][] data = new Object[70][1000];
					    //^ to display 70 rows in JTable											
		String word[] = null;
		boolean read = false ;


/* I was trying to work on the PDF_EXTRACTOR but couldnt complete it in time, so had to stop at this position :( */ 		

/*    		try{
			FileInputStream fstream = new FileInputStream("test.txt");
			DataInputStream in = new DataInputStream(fstream);
		        BufferedReader br = new BufferedReader(new InputStreamReader(in));

		        File file = new File("buffered.txt");
    		        FileWriter fw = new FileWriter(file);
                        BufferedWriter wr = new BufferedWriter(fw);

			StreamTokenizer fr1 = new StreamTokenizer( new FileReader("res4.txt"));

			i = 0 ;
			while( fr1.nextToken() != StreamTokenizer.TT_EOF){
				if(fr1.ttype == StreamTokenizer.TT_WORD) {	
					word[i] = fr1.sval;
					i++;
					if( i >= 5 ){
						if( (fr1.sval).toString.equals("BRANCH"))
							wr.write("BRANCH");
					}	
				}
			}
//			br.close();
			wr.close();
			
		}	
		catch(Exception wri){}

 */      
 
 
 
/* a StreamTokenizer acts just like a parser */ 
		StreamTokenizer fr = new StreamTokenizer( new FileReader("sem4.txt"));
		i = 0 ;
		j = 0 ;
		k = 0;
		while( fr.nextToken() != StreamTokenizer.TT_EOF){
			if(fr.ttype == StreamTokenizer.TT_WORD) {
      				 data[i][j] = fr.sval;
      				 if( fr.sval == "A\0" )
      				 	data[i][j] = "FAIL";
				 j++;
    			}
    			else if(fr.ttype == StreamTokenizer.TT_NUMBER) {
			        data[i][j] = (int)fr.nval;
				j++;
    			}
    			if( j % 12 == 0 ){
    			
    				j = 0;
    				fail = false;
    				credits = 0;
    				gpa = 0;
    				for( k =3 ; k < 9 && fail != true ; k++ ){		// GPA calculator
    					credits += 4;
    					if( data[i][k].toString().equals("A"))
    						gpa += 36;
    					else if( data[i][k].toString().equals("B") )
    						gpa += 32;
    					else if( data[i][k].toString().equals("S" ))
    						gpa += 40;
    					else if( data[i][k].toString().equals("C" ))
    						gpa += 28;
    					else if( data[i][k].toString().equals("D" ))
    						gpa += 24;
    					else if( data[i][k].toString().equals("E" ))
    						gpa += 20;
    					else if( data[i][k].toString().equals("F" ))
    						fail = true;
    					else if( data[i][k].toString().equals("X" ))
    						credits -= 4;
    				}
    				for( k =9 ; k < 11 && fail != true ; k++ ){
    					credits += 1.5;
    					if( data[i][k].toString().equals("A" ))
    						gpa += 13.5;
    					else if( data[i][k].toString().equals("B" ))
    						gpa += 12;
    					else if( data[i][k].toString().equals("S" ))
    						gpa += 15;
    					else if( data[i][k].toString().equals("C" ))
    						gpa += 10.5;
    					else if( data[i][k].toString().equals("D" ))
    						gpa += 9;
    					else if( data[i][k].toString().equals("E" ))
    						gpa += 7.5;
    					else if( data[i][k].toString().equals("F" ))
    						fail = true;
    					else if( data[i][k].toString().equals("X" ))
    						credits -= 1.5;
    					
    				}
    				gpa /= credits;
    				if( fail != true )
	    				data[i][12] = gpa;
    				i++;			
    			}
    		}
    	
        final JTable table = new JTable(data, columnNames);
        table.setPreferredScrollableViewportSize(new Dimension(1000,1000));
        table.setFillsViewportHeight(true);
        table.setAutoCreateRowSorter(true);
        JScrollPane scrollPane = new JScrollPane(table);
        add(scrollPane);
        table.getTableHeader().setToolTipText(
        "Click to sort");
    }
    catch(IOException e){}
}


/* a routine to display the result in the form of GUI */
    private static void createAndShowGUI() {

        JFrame frame = new JFrame("RESULTS !.... CLICK THE HEADER TO SORT ACCORDINGLY");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        resultView newContentPane = new resultView();
        newContentPane.setOpaque(true); 
        frame.setContentPane(newContentPane);


        frame.pack();
        frame.setVisible(true);
    }

/* The class which contains the "main" , the HEART of the code */
    public static void main(String[] args) {

        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
    }
}
