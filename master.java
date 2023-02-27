import java.util.Scanner;
import java.io.*;

class master{

	public static void main(String[] args)
	{
	display john = new display();
	john.print();
	Lanalysis lex = new Lanalysis();
	int pr = 0;
	int [] outcome = new int [100];
	// File handler as required in the task
	try{
	File file = new File("file.txt");
	Scanner read = new Scanner (file);
	String line = null;
	while(read.hasNextLine()){
	line = read.nextLine();
	System.out.println(line);
	outcome[pr] = lex.Ana(line);
	pr+=1; 
	}
	}
	catch(IOException e){
	e.printStackTrace();
	}
	// display of output
	int cs = 0;	 
	while(cs != pr)
	{
	if(outcome[cs] == 1){
	 System.out.print("Line");
	 System.out.print(cs + 1);
	 System.out.println(": True");
	}
	else if(outcome[cs] ==2){
	System.out.print("Line");
	System.out.print(cs + 1);
	System.out.println(": False");
	}	  
	cs+=1;
	}
	}
}
