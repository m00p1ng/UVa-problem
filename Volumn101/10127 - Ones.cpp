#include <cstdio>

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        int sum = 0, cnt = 0;
        do {
            sum = sum*10 + 1;
            sum %= n;
            cnt++;
        } while(sum);
        printf("%d\n", cnt);
    }
}

