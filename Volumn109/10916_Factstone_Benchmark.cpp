#include <cstdio>
#include <cmath>

int factstone[30];

void gen_factstone() {
    double sum = 0;
    int run = 2;

    for(int i = 1; i <= 21; i++) {
        double peak = log(2)*(1<<(i+1));

        while(sum <= peak) {
            sum += log(run);
            run++;
        }
        factstone[i] = run-2;
    }
}

int main() {
    int n;
    gen_factstone();

    while(scanf("%d", &n), n) {
        printf("%d\n", factstone[(n-1950)/10]);
    }
}
