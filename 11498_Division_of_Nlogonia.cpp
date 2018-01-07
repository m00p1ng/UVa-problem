#include <cstdio>

int main() {
    int ts;
    int n, m, x, y;
    while(scanf("%d", &ts), ts != 0) {
        scanf("%d %d", &n, &m);
        while(ts--) {
            scanf("%d %d", &x, &y);
            if(x == n || y == m) puts("divisa");
            else if(x > n && y > m) puts("NE");
            else if(x < n && y > m) puts("NO");
            else if(x > n && y < m) puts("SE");
            else if(x < n && y < m) puts("SO");
        }
    }
}
