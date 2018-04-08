#include <cstdio>

int main() {
    int g;
    int n;

    while(scanf("%d", &g) == 1) {
        int cnt = 0;
        for(int i = 0; i < 5; i++) {
            scanf("%d", &n);
            if(n == g) cnt++;
        }
        printf("%d\n", cnt);
    }
}
