#include <stdio.h>
/*counts the occurenceis of four*/
int main(){
    int candy;
    int i=0;
    while(1){
        scanf("%d", &candy);
        if(candy == 4){
            i++;
        }else{
            break;
        }
    }
    printf("%d",i);
    return 0;
}