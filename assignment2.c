#include <stdio.h>
void pattern(int a);
int main(){
    int n;

    printf("Enter the number of rows: ");
    scanf("%d",&n);

    if(n%2 == 0){
        printf("Please enter an odd number");
    }else{
        pattern(n);
    }
    return 0;
}
void pattern(int a){
    int i,j;
    int countb, countstar;

    for(i=0; i<a; i++){
        countb = i;
        countstar = a-2 * countb;

        for(j=0; j<countb; j++){
            printf("b");
            }

        for(j=0; j<countstar; j++){
            printf("*");
        }

        for(j=0; j<countstar; j++){
            printf("b");
        }
        printf("\n");
    }
}