#include <cstdio>
#include <cstring>

int main() {
    int ts, n;
    int a[1000010], b[1000010];
    scanf("%d", &ts);

    while(ts--) {
        memset(a, 0, sizeof(a));
        scanf("%d", &n);
        for(int i = n-1; i >= 0; i--) {
            scanf("%d %d", &a[i], &b[i]);
        }
        for(int i = 0; i < n; i++) {
            int c = (a[i]+b[i]) / 10;
            a[i] = (a[i] + b[i]) % 10;
            a[i+1] += c; 
        }
        if(a[n] != 0) printf("1");
        for(int i = n-1; i >= 0; i--) {
            printf("%d", a[i]);
        }
        puts("");
        if(ts) puts("");
    }
}
