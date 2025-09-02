#include <stdio.h>
int main(){
    int arr[100];
    int n,i, sum=0, largest,smallest;
    int search, count=0;

    /*number of elements in the array*/
    printf("Enter the number of elements you wish to store:\t");
    scanf("%d",&n);

    if(n <= 0 || n >= 100){
        printf("Please enter a number btween 1 and 100");
        return 1;
    }

    printf("Enter %d integers: \n", n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    largest = arr[0];
    smallest = arr[0];

    for(i=0 ; i<n; i++){
        /*sum of all numbers in the array*/
        sum += arr[i];
        /*largest and smallest*/
        if(arr[i] > largest){
            largest = arr[i];
        }
        if(arr[i] < smallest){
            smallest = arr[i];
        }
    }
    /*search for a specific number*/
    printf("Enter the number you want to find in the array");
    scanf("%d", &search);
    for(i=0; i<n; i++){
        if(arr[i] == search){
            count++;
        }
    }
    /*reverse the array*/
    printf("Reversed array:\n");
    for(i = n-1; i >= 0; i--){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("The sum of all the elements: %d\n",sum);
    printf("The largest number in the array: %d\n",largest);
    printf("The smallest number in the array: %d\n",smallest);
    printf("The  occurrencies of %d: %d \n",search, count);

    return 0;
}