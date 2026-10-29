#include <stdio.h>
//function practice

void arrayPrint(int arr[4]);

int main(){
    
    int mainarr[4];

    arrayPrint(mainarr[4]);
    
    return 0;
}

void arrayPrint(int arr[4]){

    for(int i=0; i<5; i++){
        printf("Enter a number: ");
        scanf("%d", &arr[i]);
    }

    printf("\nThe array is:\n");

    for(int i=0; i<5; i++){
        printf("%d \n", arr[i]);
    }
}