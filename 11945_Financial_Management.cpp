#include <cstdio>

int main() {
    int ts, f;
    double num, sum, b;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        sum = 0;
        for(int i = 0; i < 12; i++) {
            scanf("%lf", &num); 
            sum += num;
        }
        printf("%d $", t);
        sum /= 12;
        f = (int)sum/1000;
        b = ((int)sum % 1000) + (sum - (int)sum);
        if(f) printf("%d,", f);
        printf("%06.2lf\n", b);
    }
}
