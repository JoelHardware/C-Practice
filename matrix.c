#include <stdio.h>
int main(){
    int i,j,matrix[3][4];
    for(i=0; i<3; i++){
     for(j=0; j<4; j++){
      matrix[i][j] = i;
      printf("%d", matrix[i][j]);
     }
    printf("\n");
    } 
 return 0;
}