#include <cstdio>

int main() {
    int ts, total_bag = 0;
    double l, w, d, weight;

    scanf("%d", &ts);
    while (ts--) {
        bool valid = false;
        scanf("%lf %lf %lf %lf", &l, &w, &d, &weight); 

        if (((l <= 56 && w <= 45 && d <= 25) || l+w+d <= 125) && weight <= 7) {
            valid = true;
        }

        if (valid) {
            total_bag++;
            puts("1");
        } else {
            puts("0");
        }
    }
    printf("%d\n", total_bag);
}
