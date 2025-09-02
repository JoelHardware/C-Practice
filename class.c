#include <stdio.h>
void swap(int *a, int *b);
void max(int *a, int *b,int *c);
int main(){
    int n,grade[50],i,pass,fail;
    int *p;
    p = grade;

    /*number of students in the class*/
    printf("Enter the number of students in the class");
    scanf("%d",&n);
    printf("Enter the marks of the students and press e to enter");

    for(i=0;i<50;i++){
        scanf("%d",&grade);
        if(grade[i] == -1){
            fail++;
        }
        if(grade[i] > 50){
            pass++;
        }else{
            fail++;
        }
    }
    printf("Number of passed students is %d and the number of failed students is %d", pass,fail);

}
void max(int *a, int *b,int *c){
    if(*a>*b) swap(a,b);
    if(*a>*c) swap(a,c);
    if(*b>*c) swap(b,c);
}
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}