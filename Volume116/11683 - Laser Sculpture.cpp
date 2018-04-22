#include <cstdio>
int abs(int n) {
    return n > 0 ? n : -n;
}

int main() {
    int n, m;
    int cnt, prev, temp;
    while(scanf("%d %d", &n, &m), n || m) {
        scanf("%d", &temp);
        prev = temp;
        cnt = n - temp;

        for(int i = 1; i < m; i++) {
            scanf("%d", &temp);
            if(temp < prev) {
                cnt += prev - temp;
            }
            prev = temp;

        }
        printf("%d\n", cnt);
    }
}
