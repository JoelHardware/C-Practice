#include <stdio.h>
#include <string.h>
int hist(int a);
/* Exercise 1-13 Write a program to print a histogram of the lengths of words in its inputs. It is 
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.*/
int main(){
    char c[100];
    int i=0;
    int result;
    enum letters {a,z};
    gets(c);
    while(c[i] != '\0'){
        i++;
    }
    result = hist(i);
    printf("%d", result);
}
/*histogram function*/
int hist(int a){
    int j;
    for(j=0;j<a;j++){
        printf("-");
    }
    printf("\n");
}