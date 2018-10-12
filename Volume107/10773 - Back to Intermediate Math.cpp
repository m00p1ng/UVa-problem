#include <cstdio>
#include <cmath>

int main() {
    int ts;
    double d, v, u, t1, t2, diff;
    scanf("%d", &ts);

    for(int i = 1; i <= ts; i++) {
        scanf("%lf %lf %lf", &d, &v, &u);
        printf("Case %d: ", i);

        t1 = d/u;
        t2 = d/sqrt(u*u-v*v);
        diff = t2 - t1; 

        if(v >= u || diff <= 0) {
            puts("can't determine");
        } else {
            printf("%.3lf\n", t2-t1);
        }        
    }
}
