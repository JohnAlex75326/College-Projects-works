/*
*Name: John Alexander T. Sarmiento
*Subject Section: CS 11.1 A
*Date: July 13,2016
*Short Description: a program that accepts 2 integers and outputs the larger number
*/

#include<stdio.h>
int main()
{
        int x,y;
        printf("Enter value for x :");
        scanf("%d",&x);
        printf("Enter value for y :");
        scanf("%d",&y);
        if ( x > y ){
                printf("X is large number = %d\n",x);
        }
        else{
                printf("Y is large number = %d\n",y);
        }
        return 0;
}
