#include <stdio.h>
/*Sorting three integers*/
void sort3(int *xp, int *yp, int *zp);
void swap(int *a, int *b);
int main(){
    int x,y,z;
    printf("Please enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);
    sort3 (&x, &y,&z);
}
void sort3(int *xp, int *yp, int *zp){
    if  (*xp > *yp)   swap(xp, yp);
    if  (*xp > *zp)   swap(xp, zp);
    if  (*yp > *zp)   swap(yp, zp);
}
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}