#include <stdio.h>
#include <string.h>
int main(void){
    char s[80], ws[80];
    int i,j;
    printf("Enter the text:\n");
    gets(s); /* reading text from user */

for(i=0,j=0; s[i]!= '\0'; i++){
    if(s[i] != '\0', i++)
    ws[j++] = s[i];
}
ws[j] = '\0';
printf("The text without a blank space is: \n");
puts(ws);
}