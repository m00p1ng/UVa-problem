#include <cstdio>
#include <cmath>

int main() {
    int ts;
    scanf("%d", &ts);
    
    double n, p, i, result;
    while(ts--) {
        scanf("%lf %lf %lf", &n, &p, &i);

        if(p != 0) result = (pow(1-p, i-1)*p)/(1-pow(1-p, n));
        else result = 0; 

        printf("%.4lf\n", result);
    }
}
