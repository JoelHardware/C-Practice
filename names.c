#include <stdio.h>
/*Single dimensional array*/
int main(){
    char names[3][20];
    int i;
    printf("Please enter names:\n");

    for(i=0; i<3; i++){
     scanf("%19s",&names[i]);
     }

    printf("\nThe names entered are:");

    for(i=0; i<3; i++){
        printf("%s  ", names[i]);
    }
}