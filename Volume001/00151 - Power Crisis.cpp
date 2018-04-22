#include <cstdio>

int josphus(int n, int k) {
    if(n == 1) return 1;
    return (josphus(n-1, k) + k - 1) % n + 1;
}

int main() {
    int n;
    while(scanf("%d", &n), n) {
        for(int i = 1; i <= n; i++) {
            if(josphus(n-1, i) == 12) {
                printf("%d\n", i);
                break; 
            }
        }
    }
}
