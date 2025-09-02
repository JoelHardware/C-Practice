#include <stdio.h>
int main(){
    int n,i,couple[50];

    printf("Please enter the number of couples");
    scanf("%d",&n);

    printf("Please enter the ID numbers that were distributed");
    for(i=1;i<n;i++){
        scanf("%d",couple[i]);
        if(couple[i] < 50){
            printf("missing");
        }else{
            printf("Assigned");
        }
    }
}