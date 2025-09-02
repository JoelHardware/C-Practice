#include <stdio.h>
/*correction for candygame*/
int main(){
    int number, count = 0;
    printf("Enter the number: ");
    scanf("%d", &number);

    if(number < 0){
        number = -number;
    }
    

    while(number > 0){
        int digit = number % 10;
        if(digit == 4){
            count++;
        }
        number /= 10;
    }
    printf("Number of occurrencies  of four: %d", count);
    return 0;
}