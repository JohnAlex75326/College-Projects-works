#include <stdio.h>
void foo(int *p);
int main(){
int i = 97, *p = &i;
foo(p);
printf("%d ", *p);
getchar();
return 0;}

void foo(int *p)
{ int j = 2;
//p=&j; // output is 2 97
*p=j;   //output is 2 2

printf("%d ", *p);
}
