#include <cstdio>

int josphus(int n, int k) {
    if(n == 1) return 1;
    return (josphus(n-1, k) + k - 1) % n + 1;
}

int main() {
    int n;
    while(scanf("%d", &n), n) {
        int k = 1;
        while(1) {
            if(josphus(n-1, k) == 1) {
                printf("%d\n", k);
                break; 
            }
            k++;
        }
    }
}
