#include <stdio.h>
#include <string.h>
int main(){
    char txt[100];
    int i=0;
    printf("Enter any string you want: ");
    gets(txt);
    while(txt[i] != '\0'){
        i++;
    }
    printf("String length = %d\n",i);
    printf("String lenth using strlen is %d\n", strlen(txt));
}
