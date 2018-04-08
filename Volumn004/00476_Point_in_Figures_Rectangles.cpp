#include <cstdio>

int main() {
    double sq[10][4];
    double a, b;
    int c = 0, p = 1;
    bool is_contain;
    char r;

    while(scanf(" %c", &r), r != '*') {
        scanf(" %lf %lf %lf %lf", &sq[c][0], &sq[c][1], &sq[c][2], &sq[c][3]);
        c++;
    }
    while(scanf("%lf %lf", &a, &b), a != 9999.9 || b != 9999.9) {
        is_contain = false;
        for(int i = 0; i < c; i++) {
            if(sq[i][0] < a && sq[i][2] > a && sq[i][1] > b && sq[i][3] < b) {
                printf("Point %d is contained in figure %d\n", p, i+1);
                is_contain = true;
            }
        }
        if(!is_contain) {
            printf("Point %d is not contained in any figure\n", p);
        }
        p++;
    }
}

