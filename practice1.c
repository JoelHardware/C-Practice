#include <stdio.h>
int main (){
    char a[5][100];
    int i;

    printf("Please enter a new task: \n");

    for(i=0; i<5; i++){
     printf("Task %d", i +1);
     scanf(" %[^\n]s", &a[i]);
    }

    printf("\nYou entered the following tasks:\n");

    for(i=0; i<5;i++){
        printf("Task %d: %s\n", i + 1, a[i]);
    }

    return 0;
}

char done(char a, char b){
    while ((a = getchar()) != 'a'){
        printf("TASK DONE");
    }
}