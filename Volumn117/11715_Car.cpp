#include <cstdio>
#include <cmath>

int  main() {
    int cmd;
    int cs = 1;
    while(scanf("%d", &cmd), cmd) {
        double a, b, c;
        scanf("%lf %lf %lf", &a, &b, &c);
        printf("Case %d: ", cs++);
        double ans1, ans2;
        switch(cmd) {
            case 1:
                ans1 = (a+b)*c/2.0;
                ans2 = (b-a)/c;
                break;
            case 2:
                ans1 = (b*b-a*a)/(2*c);
                ans2 = (b-a)/c;
                break;
            case 3:
                ans1 = sqrt(a*a+2*b*c);
                ans2 = (ans1 - a)/b;
                break;
            case 4:
                ans1 = sqrt(a*a-2*b*c);
                ans2 = (a - ans1)/b;
                break;
        }
        printf("%.3lf %.3lf\n", ans1, ans2);
    }
}

