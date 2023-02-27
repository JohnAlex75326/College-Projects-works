/*
*Name: John Alexander Sarmiento
*Subject Section: CS 11.1 A
*Date: August 3 2016
*Description: Fibonacci Series
*/
#include <stdio.h>

int main() {
	int n = 0;
	int x = 0;
	int y = 1;
	int a = 1;
	int sum = 0;
	//getting user input
	printf("enter a number and it will look for its fibonacci sequence.\n");
	printf("enter a number: ");
	scanf("%d", &n);
	
	//process
	for (a=1; n>a; a++){
		sum= x+y;
		x=y ;
		y=sum ;
	}
		{printf("%d", x);
	}	
	}
