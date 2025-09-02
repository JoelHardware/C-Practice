#include <stdio.h>
/*Double dimensional array*/
int main (){
    int i,j,array[4][3];

    for(i=0; i<4; i++){
     for(j=0; j<3; j++){
      array[i][j] = i+j;
      printf("%d", array[i][j]); 
     }
    printf("\n");
    }
 return 0;
}