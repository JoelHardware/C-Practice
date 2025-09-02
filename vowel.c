#include <stdio.h>
/*Write a program to find the frequency of vowels in a paragraph.*/
int hist(int a, char b);
int main(){

    int count[] = {0,0,0,0,0};
    enum vowel {a,e,i,o,u};
    int c, r1, r2, r3, r4, r5;

    /*Counting the number of each vowel*/
    while((c = getchar()) != EOF){
        switch (c){
            case 'a':
             count[a]++;
            break;
            case 'e':
             count[e]++;
            break;
            case 'i':
             count[i]++;
            break;
            case 'o':
             count[o]++;
            break;
            case 'u':
             count[u]++;
            break;
        }
    }
    /*function call for vertical histogram*/
    r1 = hist(count[a], 'a');
    r2 = hist(count[e], 'e');
    r3 = hist(count[i], 'i');
    r4 = hist(count[o], 'o');
    r5 = hist(count[u], 'u');
}
/*function for a vertical histogram*/
int hist(int a, char b){
    int j;
    printf("%c:", b);
    for(j=0;j<a;j++){
        printf("-");
    }
    printf("\n");
}