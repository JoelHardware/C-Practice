#include <stdio.h>
int main (){
    
    int c;
    char words[30] [200];
    int i = 0;
    int j = 0;

    while ((c = getchar()) != EOF){
        if(c == ' ' || c == '\n'){
            words[i][j] = '\0';
            i++;
            j = 0;
        }
        else{
            words[i][j] = c;
            j++;
        } 
    }
    for(int k = 0; k <100; k++){
        printf("%d is %s ");
    }
}