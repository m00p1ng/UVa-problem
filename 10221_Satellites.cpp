#include <cstdio>
#include <cmath>
#define PI acos(-1)

int main() {
    double s, a;
    char cmd[10];
    
    while(scanf("%lf %lf %s", &s, &a, cmd) == 3) {
        if(cmd[0] == 'm') a /= 60.0;
        else if(a > 180) a = 360-a;
        a *= PI/180.0;
        
        double r = 6440 + s;
        double dist = r*sqrt(2*(1-cos(a)));
        double arc = r*a;
        printf("%.6lf %.6lf\n", arc, dist);
    }
}
