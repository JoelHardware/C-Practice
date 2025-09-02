 #include <stdio.h>
 #include <math.h>
 typedef int bool;
 double m_abs(double);
 double new_guess(double x, double guess);

 bool is_good_enough(double x,double guess, double t);

 double m_sqrt(double x){
    double guess = 1;
    double t = 0.00001;
    while (! is_good_enough(x,guess,t)){
        guess = new_guess(x,guess);
    }
    return guess;
 }
 double new_guess(double x, double guess){
    return(x/guess + guess)/2;
 }
 bool is_good_enough(double x, double guess, double t){
    return m_abs(x-guess*guess)<t;
 }
 double m_abs(double x){
    if(x<0){
        return -x;
    }
    return x;
 }
int main(){
    for (double x=4; x<30; x+=1)
     printf("Root of %1f is %1f\n", 16.0, m_sqrt(16));
}