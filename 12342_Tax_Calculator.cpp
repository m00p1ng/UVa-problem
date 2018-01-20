#include <cstdio>
#include <cmath>

int main() {
    int ts, income;
    double tax;
    scanf("%d", &ts);

    for(int t = 1; t <= ts; t++) {
        scanf("%d", &income);

        tax = 0;
        income -= 180000;
        if(income > 300000) {
            tax += 30000;
            income -= 300000;
        } else if(income > 0) {
            tax += income*0.1;
            income = 0;
            if(tax < 2000) tax = 2000;
        }
        if(income > 400000) {
            tax += 60000;
            income -= 400000;
        } else if(income > 0) {
            tax += income*0.15;
            income = 0;
        }
        if(income > 300000) {
            tax += 60000;
            income -= 300000;
        } else if(income > 0) {
            tax += income*0.2;
            income = 0;
        }
        if(income > 0) {
            tax += income*0.25;
            income = 0;
        }
        printf("Case %d: %.0lf\n", t, ceil(tax));
    }
}
