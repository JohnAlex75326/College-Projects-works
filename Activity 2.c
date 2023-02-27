/*
 *Kyle Ruzzel A. Pamakid
 *BSCS 1-A
 *CS 12
 *November 16 2016
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int winningCombi(int winningNumber[6]); //winning number prototype
int input(int userInput[6]);

int main()
{
	 //Declaring Variables
	int ctr = 0;	//counter
	int userInput[6]; //array to send to the input
	int winningNumber[6];	//array to send to the winningCombi function to get an array
    
    	winningCombi(winningNumber);	//winningCombi function
	
		printf("\nEnter 6 numbers from 1-55 and get a chance to win 30 Million Pesos!\n");
		
		input(userInput);
	
	 //loop to check how many numbers are equal with the user input and the winning number
    int i, j;	//counters
	int howmany = 0;	//this will determine how many numbers are equal with the user input and the winning numbers
	    for (i = 0;i < 6;i++)
	    {
				for (j = 0;j < 6;j++)
	        	{
	        		if (userInput[i]==winningNumber[j])
	            	{
	              		howmany++;
	            	}
	        	}
	                
	    }
	    
	    //Output to display if you won or not
	   printf("\n\nYou got %d numbers right", howmany);
	   if (howmany == 6)
	   {	
			printf("\n\nCongratulations! You won the Jackpot of 30 Million by matching all 6 Numbers\n\n");
	   }
	   else if (howmany == 5)
	   {
	   		printf("\n\nCongratulations! You won 200,000 pesos by matching 5 Number\n\n");
	   }
	   else if (howmany == 4)
	   {
	   		printf("\n\nCongratulations! You won 3000 pesos by matching 4 Numbers\n\n");
	   }
	   else if (howmany == 3)
	   {
	   		printf("\n\nCongratulations! You won 20 Pesos by matching 3 Numbers!\n\n");
	   }
	   else 
	   {
	   		printf("\n\nSorry, Better Luck next time!");
	   }
	
	//to display the winning combination
		printf("\n\n\n\n                            The Winning Numbers are: \n");
		for (ctr = 0; ctr < 6; ctr ++)
		{ 
			printf("%11d ", winningNumber[ctr]);
		}
		getchar();
		scanf("%d",ctr);	getchar();
		return 0;
}


 
//function for the winning Combination
int winningCombi(int random[6])
{
	int ctr,ctr1;
		srand(time(NULL));
for(ctr=0; ctr<6; ctr++)
	{
		random[ctr]=rand() % 55 + 1;
		for(ctr1=0; ctr1<6; ctr1++)
		{
			if(random[ctr]==random[ctr1])
			{
				if(ctr1!= ctr)
				{
					random[ctr]= rand() % 55 +1;
					ctr1=0;
				}
			}
		}
}
}

//function for user input
int input(int y[6])
{
	int ctr;	//counter
		for (ctr = 0; ctr < 6; ctr++)
	{
    	scanf("%d", &y[ctr]);
    		if (y[ctr]==y[ctr-1])
    		{
    			printf("Do not repeat a number.\n"); //if a user repeats a number
    			ctr--;
			}
			if ((y[ctr]<1)||(y[ctr]>55))
			{
				printf("Only input numbers up to 55\n"); //if a user exceeds 55
				ctr--;
			}
			
	}

	
}
