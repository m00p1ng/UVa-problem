#include <cstdio>

int main() {
    int n, d;
    while(scanf("%d %d", &n ,&d), n && d) {
        int b[100];
        for(int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
        }

        for(int i = 0; i < d; i++) {
            int x, y, v;
            scanf("%d %d %d", &x, &y, &v);
            b[x] -= v;
            b[y] += v;
        }

        bool is_valid = true;
        for(int i = 1; i <= n; i++) {
            if(b[i] < 0) {
                is_valid = false;
                break;
            }
        }

        if(is_valid) puts("S");
        else puts("N");
    }
}


