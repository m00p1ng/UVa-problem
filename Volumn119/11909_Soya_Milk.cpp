#include <cstdio>
#include <cmath>

double rad(double theta) {
    return theta*M_PI/180.0;
}

int main() {
    double l, w, h, theta;
    double hprime, area;

    while(scanf("%lf %lf %lf %lf", &l, &w, &h , &theta) == 4) {
        hprime = l*tan(rad(theta));
        if(hprime <= h) area = l*(h-hprime/2); 
        else area = h*h*tan(rad(90 - theta))/2; 
        printf("%.3lf mL\n",area*w);
    }
}

