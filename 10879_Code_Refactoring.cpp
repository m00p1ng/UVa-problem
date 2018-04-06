#include <cstdio>

int main() {
    int ts, n;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        scanf("%d", &n);
        int is_found = false;
        for(int i = 2; i < n/2 && !is_found; i++) {
            if(n % i == 0) {
                for(int j = i+1; j < n/2; j++) {
                    if(n % j == 0) {
                        is_found = true;
                        printf("Case #%d: %d = %d * %d = %d * %d\n", t, n, i, n/i, j, n/j);
                        break;
                    }
                }
            }
        }
    }
}
