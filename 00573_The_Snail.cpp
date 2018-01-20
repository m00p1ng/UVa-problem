#include <cstdio>

int main() {
    double h, u, d, f;
    double curr, fat;
    int day;

    while(scanf("%lf %lf %lf %lf", &h, &u, &d, &f), h) {
        day = curr = 0;
        fat = f*u/100.0;
        while(1) {
            day++;
            curr += u;
            
            if(curr > h) break;
            curr -= d;
            u = u > fat ? u-fat : 0;

            if(curr < 0) break;
        }

        if(curr >= h) printf("success on day %d\n", day);
        else printf("failure on day %d\n", day);
    }
}
