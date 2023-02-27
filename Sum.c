/*
*Name: John Alexander T. Sarmiento
*Subject Section: CS 11.1 A
*Date: June 29,2016
*Short Description: a program that adds the values of the user input
*/

#include <stdio.h>

void main()
{

	int input;
	int user;
	int shh;

	printf("\n\n this program doubles the value of an integer.\n");

	printf("Enter 1st integer: ");

	scanf("%d" , &input);
	printf("Enter 2nd integer: ");
	scanf("%d" ,&shh);

	user = input + shh;
	printf("the answer is: %d \n\n" , user);
}