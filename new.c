/* 
* Name: John Alexander T. Sarmiento
* Subject Section: CS 11.1 A
* Date: July 16,2016
* Short Description: A program that sorts 3 numbers into ascending order
*/

#include <stdio.h>
	int main()
	{
	int x =0; 	//variable for first input
	int y =0;	//variable for second input
	int z =0;	//variable for third input
			
	// ask for user input
	printf("enter first number :");
	scanf("%d" ,&x);
	printf("enter second number :");
	scanf("%d" ,&y);
	printf("enter third number :");
	scanf("%d" ,&z);
	//process 
	if (x>y)
	{
		if (x>z)
		{
			if (y>z)
			{
				printf("%d : %d : %d",z,y,x);
			}
			else
			{
				printf("%d : %d : %d",y,z,x);
			}
		}
		else
		{
			printf("%d : %d : %d",y,x,z);
		}
	}
	else
	{
		if (y>z)
		{
			if (x>z)
			{
				printf("%d : %d : %d",z,x,y);
			}
			else
			{
				printf("%d : %d : %d",x,z,y);
			}
		}
		else
		{
			printf("%d : %d : %d",x,y,z);
		}
	}	
	}
			
