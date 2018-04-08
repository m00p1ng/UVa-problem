#include <cstdio>

int main() {
    int ts;
    int c, d;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        scanf("%d %d", &c, &d);
        printf("Case %d: %.2lf\n", t, c + d*5/9.0);
    }
}
