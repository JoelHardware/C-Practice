#include <stdio.h>
void swap(int *x,int *y);
void sort(int *xp, int *yp, int *zp);
float avg(int array[], int num);
int main(){
    int grade[100],i,students;

    printf("Please enter the number of students.");
    scanf("%d",&students);
    printf("Please enter the grade of each student. Press e to enter");
    while(getchar() != 'e'){
        scanf("%d\n",&grade[100]);
    }

    for(i=0;i<students;i++){
        scanf("%d",&grade[students]);
    }
    printf("The average grade for the class is: %f", avg(grade,students));

}
float avg(int array[], int num){
    int *p, i, sum=0;
    p = array;
    for(i=0; i<num; i++){
        sum = sum + *(p+1);
        return((float)sum/num);
    }
}
void sort(int *xp, int *yp, int *zp){
    if(*xp > *yp) swap(xp,yp);
    if(*xp > *zp) swap(xp,yp);
    if(*yp > *zp) swap(yp,zp);
}
void swap(int *x,int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}