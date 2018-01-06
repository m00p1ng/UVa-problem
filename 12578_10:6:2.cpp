#include <cstdio>
#include <cmath>

#define PI acos(-1)

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        int len;
        scanf("%d", &len);
        
        double cir = 0.04*len*len*PI;
        double sq  = 0.6*len*len - cir;

        printf("%.2lf %.2lf\n", cir, sq);
    }
}
