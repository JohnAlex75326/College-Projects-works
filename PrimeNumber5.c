/* Name: John Alexander Sarmiento
/ Subject Section: CS 11.1 A
/ Date: Aug 20, 2016
/ Program Description: Determines whether a positive integer is a PRIME NUMBER
*/

#include <stdio.h>
int main() {
	int num;
	int i = 2;
	int Prime = 0;
	
	//user input
	printf("Enter a positive number\n");
	scanf("%d",&num);
	
	// process: to check if the given input is divisible by 2
	for (i=2; i<=(num/2); i++) {
		if(num%i==0){
		Prime=1;	
		}
	}
	if(Prime==0)
		printf("%d is a Prime Number",num);
	else
		printf("%d is Not a Prime Number",num);
		
	}

