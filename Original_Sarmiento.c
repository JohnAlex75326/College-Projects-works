/*
* John Alexander Sarmiento 
* CS 12 Jan 11 2017
* Program Description: The program integrates the use of the array and the pointer. 
* The Program will ask for 10 numbers of user input twice.
* Then proceed to swapping each element of the first array to the second array by using the function I called "swap"
* Sample input 1st array: 1 2 3 4 5 6 7 8 9 10	2nd array: 11 12 13 14 15 16 17 18 19 20
* Output: 1st Array: 11 12 13 14 15 16 17 18 19 20	2nd Array: 1 2 3 4 5 6 7 8 9 10
* Disclaimer: I do NOT claim that this is a problem that I created, I simply found it at http://www.sanfoundry.com/c-program-swap-array-elements-using-pointers/
* rather than copy the entire code I decided to do a little tweaking into it to come up with a solution that is more familiar to me.
*/

#include <stdio.h>
void swap(int *, int *);

int main(){

int x[10],y[10],ctr;

printf("Enter 1st array: ");

for(ctr=0;ctr<10;ctr++)

scanf("%d",&x[ctr]);

printf("\nEnter 2nd array: ");

for(ctr=0;ctr<10;ctr++)

scanf("%d",&y[ctr]);

for(ctr=0;ctr<10;ctr++)
swap(&x[ctr], &y[ctr]);


printf("\n\n");
printf("\nArrays after swapping");
printf("\n1st array: ");
for(ctr=0;ctr<10;ctr++)
printf("%d ",x[ctr]);

printf("\n2nd array: ");
for(ctr=0;ctr<10;ctr++)
printf("%d ",y[ctr]);
getchar();
}


void swap(int *arr1, int *arr2){
	int temp;
	temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

