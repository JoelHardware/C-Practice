#include <stdio.h>
#include <math.h>
int divisors(int n);
int count_aes(int low, int high);

int main(){
    int low,high;
    printf("Enter the lower limit then upper limit of the range of numbers: ");

    scanf("%d %d",&low,&high);

    printf("The given range has %d AES numbers.", count_aes(low,high));
}

//checking for the number of divisors of the number
int divisors(int n){
    int count = 0, i;
    for(i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            if(i == n/i){
                count += 1;
            }
            else{
                count += 2;
            }
        }
    }
    return count;
}

//counting the aes numbers in the given range using the divisor function
int count_aes(int low, int high){
    int count = 0, num;
    for(num = low; num <= high; num++){
        if(divisors(num) == 4){
            count++;
        }
    }
    return count;
}
