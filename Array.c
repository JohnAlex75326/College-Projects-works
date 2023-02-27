/* John Alexander T. Sarmiento
* CS 11.1 A
* September 21 2016
* A program that uses Arrays. Displays sum and average of 10 integers, identifies the highest and lowest number, sorts in ascending,
then displays the content of the array
*/

#include <stdio.h>
int main(){
	int input[10];
	int ctr=0;
	int sum=0;
	int high;
	int low;
	int cbr;
	int sqr;
	
	//user input
	for(ctr=0;ctr<10;ctr++){
		printf("Enter a number %d: ",ctr);
		scanf("%d", &input[ctr]);
	
	//Calculating the sum and the average of the integers
	sum=sum+input[ctr];
	
	//getting the highest and lowest
	if (input[ctr]>high)
	{
		high=input[ctr];
	}
	else 
	{
		low=input[ctr];
	}
}
	printf("Highest: %d\n\n",high);
	printf("Lowest: %d\n\n",low);
	printf("The sum of the integers is %d\n",sum);
	printf("the average of the integers is %d\n",sum/10);
	
	//Sorts in ascending order 
	for(ctr=0;ctr<10;ctr++){
		for(cbr=ctr+1;cbr<10;cbr++){
		
		if (input[ctr]>input[cbr])
		{
			sqr=input [ctr];
			input[ctr]=input[cbr];
			input[cbr]=sqr;
		}
	}
	}
	//Displaying the array
	for(ctr=0;ctr<10;ctr++){
		printf("Array[%d]: %d\n",ctr,input[ctr]);
	}
		if (input[ctr]%2==0){
	
		printf("[%d]",input[ctr]);}	

}
