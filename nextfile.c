#include <stdio.h>
#include <math.h>
//Elliptic Curve Point Addition

int inverse_mod(int a, int p);
int mod(int a, int p);

int main(){
    int T;
    scanf("%d", &T);

    while(T--){
        int a,b,p,x1,y1,x2,y2,slope;
        int x3, y3, numerator, denominator;
        scanf("%d %d %d %d %d %d %d", &a, &b, &p, &x1, &y1, &x2, &y2);  
        
        if(x1==x2 && y1==(p - y2) % p){
            printf("POINT_AT_INFINITY\n");
            continue;
        }

        if(x1==x2 && y1==y2){
            numerator = mod(3 * x1 * x1 + a, p);
            denominator = inverse_mod(2 * y1, p);
            slope = mod(numerator * denominator, p);
        }
        else{
            numerator = mod(y2 - y1, p);
            denominator = inverse_mod(x2 - x1, p);
            slope = mod(numerator * denominator, p);
        }

        x3 = mod(slope * slope - x1 -x2, p);
        y3 = mod(slope * (x1 - x3) - y1, p);

        printf("%d %d\n", x3, y3);
    }
    
    return 0;
}

int mod(int a, int p){
    a %= p;
    if(a<0){
        a += p;
    }
    return a;
}

int inverse_mod(int a, int p){
    int result = 1;
    int exponent = p - 2;

    a %= p;

    while(exponent > 0){
        if(exponent % 2 == 1){
            result = (result * a) % p;
        }
        a = (a * a) % p;
        exponent /= 2;
    }
    return result;
}