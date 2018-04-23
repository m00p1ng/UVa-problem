#include <cstdio>

int abs(int n) {
    return n > 0 ? n : -n;
}

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        int n, q;
        int a, b, c, d;
        scanf("%d %d", &q, &n);
        for(int i = 0; i < q; i++) {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            if((a+b)%2 != (c+d)%2) {
                puts("no move");
            } else {
                if(a == c && b == d) puts("0");
                else if(abs(a-c) == abs(b-d)) puts("1");
                else puts("2");
            }
        }
    }
}
