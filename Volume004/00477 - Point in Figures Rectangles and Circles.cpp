#include <cstdio>

int main() {
    double d[10][4];
    char f[11], temp;
    double a, b;
    int p = 1, c = 0;
    bool is_contain;

    while(scanf(" %c", &temp), temp != '*') {
        f[c] = temp;
        if(temp == 'r') scanf(" %lf %lf %lf %lf", &d[c][0], &d[c][1], &d[c][2], &d[c][3]);
        if(temp == 'c') scanf(" %lf %lf %lf", &d[c][0], &d[c][1], &d[c][2]);
        c++;
    }

    while(scanf("%lf %lf", &a, &b), a != 9999.9 || b != 9999.9) {
        is_contain = false;
        for(int i = 0; i < c; i++) {
            switch(f[i]) {
                case 'r':
                    if(d[i][0] < a && d[i][2] > a && d[i][1] > b && d[i][3] < b) {
                        printf("Point %d is contained in figure %d\n", p, i+1);
                        is_contain = true;
                    }
                    break;
                case 'c':
                    if((a-d[i][0])*(a-d[i][0]) + (b-d[i][1])*(b-d[i][1]) < d[i][2]*d[i][2]) {
                        printf("Point %d is contained in figure %d\n", p, i+1);
                        is_contain = true;
                    }
                    break;
            }
        }

        if(!is_contain) {
            printf("Point %d is not contained in any figure\n", p);
        }
        p++;
    }
}

