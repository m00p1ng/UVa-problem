#include <cstdio>

int main() {
    int ts;
    int e, f, c, total, cnt;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d %d %d", &e, &f, &c);
        total = e + f;
        cnt = 0;
        
        while(total >= c) {
            cnt += total / c;
            total = (total / c) + (total % c);
        }
        printf("%d\n", cnt);
    }
}
