#include <stdio.h>
#include <math.h>

float power(float V, float I, float angle);
float get_voltage(float V);
float get_current(float I);
float get_phase(float angle);
float power_calc(float V, float I, float angle);

int main(){
    float V = 0, I = 0, angle = 0;

    power (V ,I ,angle);
    
    return 0;
}
float get_voltage(float V){
    printf("Voltage: ");
    scanf("%f", &V);
    return V;
}

float get_current(float I){
    printf("\nCurrent: ");
    scanf("%f", &I);
    return I;
}

float get_phase(float angle){
    printf("\nPhase Angle: ");
    scanf("%f", &angle);
    return angle;
}

float power(float voltage, float current, float phase_angle){
    float V = get_voltage(voltage);
    float I = get_current(current);
    float angle = get_phase(phase_angle);

    float R= V/I;
    printf("The resistance is %f\n", R);

    float Q = I * V * sin(angle);
    printf("The reactive power is %f\n", Q);

    float P = I * V * cos(angle);
    printf("The real/active power is %f\n", P);

    float S = I * V;
    printf("The reactive power is %f", S);
}
