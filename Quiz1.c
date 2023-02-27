#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char word[10];
    int i=0,c=0;
    printf("Enter a word\n");
    scanf("%s", &word);
    c=strlen(word);
    printf("your word is %s\n\n", word);
    printf("There are %d letters in your word.\n\n",c);
    
    for (i=0; i<c; i++)
    { printf("%c",toupper(word[i]));
     }
      printf("\n\n");
     for (i=0; i<c; i++)
    { printf("%c",tolower(word[i]));
     }
     printf("\n\n");
       for (i=c-1; i>=0; i--)
    { printf("%c",(word[i]));
     }
     scanf("%d", &c);
     return 0;
     }
