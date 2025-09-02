#include <stdio.h>
int main(){
    int i,j,m,n;
    int rows,columns, max_row=0, max_column=0;
    int arr[10][10];

    /*rows and columns*/
    printf("Enter the number of rows:\n");
    scanf("%d", &m);
    printf("Enter the number of columns:\n");
    scanf("%d", &n);

    printf("Enter matrix values:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    /*Maximum row*/
    printf("Enter a row number:\n");
    scanf("%d", &rows);
    max_row = arr[rows - 1][0];
    for(i=1; i<n; i++){
        if(arr[rows - 1][i] > max_row){
            max_row = arr[rows - 1][i];
        }
    }
    printf("The maximum value in row %d is %d", rows, max_row);

    /*Maximum column*/
    printf("Enter a column number:\n");
    scanf("%d", &columns);
    max_column = arr[columns - 1][j];
    for(j=1; j<m; j++){
        if(arr[columns - 1][j] > max_column){
            max_column = arr[columns - 1][j];
        }
    }
    printf("The maximum value in column %d is %d", columns, max_column);

    return 0;
}