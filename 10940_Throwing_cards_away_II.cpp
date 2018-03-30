#include <cstdio>
#include <cmath>

int main() {
    int n;
    while(scanf("%d", &n), n) {
        if(n == 1) puts("1");
        else {
            int sq = log2(n-1);
            printf("%d\n", 2*(n-(1<<sq)));
        }
    }
}

