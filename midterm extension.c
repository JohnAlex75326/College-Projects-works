/*Name: John Alexander Sarmiento
*Date: August 17 2016
*Midterm Extension 
* Description: Sum of all even numbers of input 1 and 2
*/
#include <stdio.h>
	int main() {
		int input1=0;
		int input2=0;
		int ctr	=0;
		int sum= 0;
		//input
		printf("enter 1st input");
		scanf("%d",&input1);
		printf("enter 2nd input");
		scanf("%d",&input2);
		//process
		for(ctr=input1;ctr<=input2;ctr++) {
			if(ctr%2==0){	//to make sure its even
				sum=sum+ctr;
			}
		}
			printf("%d",sum);		
	}

	
