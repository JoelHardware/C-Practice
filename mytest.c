#include <stdio.h>
int main(){
    int a,i;
    char c;
    printf("Enter anything you want");
    while((c = getchar()) != 'A'){
     for(i=0; i<4; i++){
        printf("%d. Practice to compile and run\n", i++);
     }
    }
    printf("Try again");
    return 0;
}