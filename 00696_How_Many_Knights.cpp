#include <cstdio>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int m, n, result;
    while(scanf("%d %d", &m, &n), m || n) {
        if(min(m, n) == 1) {
            result = n == 1 ? m : n; }
        else if(min(m, n) == 2) {
            int M = max(m, n)-1;

            if(M % 4 == 0) result = M+2;
            else result = (M/4+1)*4;
        } else result =(m*n+1)/2;
        printf("%d knights may be placed on a %d row %d column board.\n", result, m, n);
    }
}

