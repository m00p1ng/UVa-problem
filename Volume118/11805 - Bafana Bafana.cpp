#include <cstdio>

int main() {
    int ts;
    int n, k, p, out;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        scanf("%d %d %d", &n, &k, &p);
        out = (k+p)%n;
        if(out == 0) out = n;
        printf("Case %d: %d\n", t, out);
    }
}
