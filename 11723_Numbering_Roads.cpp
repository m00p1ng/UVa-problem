#include <cstdio>

int main() {
    int n, r;
    int cnt = 0;

    while(scanf("%d %d", &n, &r), n || r) {
       int req = (n/r) + (n%r != 0) - 1;

       printf("Case %d: ", ++cnt);
       if(req > 26) puts("impossible");
       else printf("%d\n", req);
    }
}
