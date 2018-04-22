#include <cstdio>

int main() {
    int a, b, c, d, l;

    while(scanf("%d %d %d %d %d", &a, &b, &c, &d, &l), a || b || c || d || l) {
        int cnt = 0, f;
        for(int i = 0; i <= l; i++) {
            f = a*i*i + b*i + c;
            if(f % d == 0) cnt++;
        }
        printf("%d\n", cnt);
    }
}
