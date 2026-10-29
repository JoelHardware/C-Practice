#include <stdio.h>
#include <math.h>
float bodyTemp(float temp);
int oxygenLevel(int oxygen);

int main(){
    float temperature = 0;
    int oxygen = 0;

    printf("Enter the patient's body temperature: ");
    float patientTemp = bodyTemp(temperature);
    printf(" your temperature is %.2lf \n", patientTemp);

    printf("Enter the patient's blood oxygen level: ");
    int patientOxygen = oxygenLevel(oxygen);
    printf("your O2 level is %d\n", patientOxygen);

    return 0;
}

float bodyTemp(float temp)
{
    scanf("%f", &temp);
    if(temp<35){
        printf("Temperature too low ");
    }
    else if(temp>35 && temp<=37){
        printf("Temperature within normal range ");
    }
    else{
        printf("Temperature too high ");
    }
    return temp;
}

int oxygenLevel(int oxygen){
    scanf("%d", &oxygen);

    if(oxygen>95 && oxygen<=100){
        printf("Oxygen level within normal range ");
    }
    else{
        printf("Oxygen outside normal range");
    }

    return oxygen;
}