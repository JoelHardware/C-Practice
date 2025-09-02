#include <stdio.h>
struct stud{
    int roll;
    char dept_code[25];
    float cgpa;
}
main(){
    struct stud class[100],t;
    int j,k,n;
    scanf("%d",&n);
    /*number of students*/

printf("Please enter the roll, department code and class GPA");
for(k=0;k<n;k++)
scanf("%d %s %f", &class[k].roll, &class[k].dept_code, &class[k].cgpa);

for(j=0;j<n-1;j++)
 for(k=j+1;k<n;k++){
    if(class[j].roll > class[k].roll){
        t = class[j];
        class[j] = class[k];
        class[k] = t;
    }
 }
 printf("The sorted list of students:");
 for(k=0; k<n; k++){
    printf("%d %s %.2f", class[k].roll, class[k].dept_code, class[k].cgpa);
 }
}