#include <stdio.h>
int main(){
    int N,even=0,odd=0;
    int i=1;
    printf("Please enter the registration codes. Type e when you have entered all codes");
    while(i==1 && getchar() != 'e'){
        scanf("%d\n", &N);
        if(N%2 == 0){
            even++;
        }else{
            odd++;
        }
    }
     printf("even: %d odd: %d", even,odd);
}
