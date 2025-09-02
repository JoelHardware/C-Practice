#include <stdio.h>
int main(){
    int i,j,n;
    int arr[10][10];
    int highest=0, position;

    printf("The class is the size of n*n.\n");
    printf("Enter the value of n:\n");
    scanf("%d",&n);

    printf("Enter the marks of students in each position:\n");
    for(i=0; i<n;i++){
        for(j=0;j<n;j++){
            printf("row %d column %d\n", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The position of nominees are:\n");
    for(i=0; i<n; i++){
        highest = arr[i][0];
        position = 1;
        for(j=1; j<n; j++){
            if(arr[i][j] > highest){
                highest = arr[i][j];
                position = j + 1;
            }
        }
        printf("%d\n",position);
    }
}