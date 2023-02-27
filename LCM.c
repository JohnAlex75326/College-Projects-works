/* Name: John Alexander Sarmiento
* Subject Section: CS 11.1 A
* Date: Aug 26, 2016
* Short description: Program that accepts 2 positive integers and Prints their LCM
*/

#include <stdio.h>
	int main() {
		int x=0;
		int y=0;
		int ctr=0;
		int lcm=0;
		//user input
		printf("\nEnter 1st number ");
		scanf("%d", &x);
		printf("\nEnter 2nd number ");
		scanf("%d", &y);
		
		//Process
		for(ctr=1; y>0; ctr++) {
			lcm=x*ctr;
			if(lcm%y==0) {
				printf("LCM is %d", lcm);
				break;
			}
		}
		
	}
