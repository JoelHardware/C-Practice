#include <stdio.h>
    /*using strings in C*/
int main(){
    /*Using scanf for strings in C*/
    char name[30];
    printf("Enter your name: ");
    scanf("%[^\n]s",name);
    printf("Hello %s",name);
}
/* The gets function can also be used to achieve the same thing.
Example:

char str[200];
printf("Enter a string :");
gets(str);
printf("The string is :%s", str);*/