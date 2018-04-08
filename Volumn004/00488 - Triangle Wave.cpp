#include <cstdio>

int main() {
    int ts;
    int n, r;

    scanf("%d", &ts);
    while(ts--) {
        scanf("%d %d", &n, &r);

        while(r--) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= i; j++) {
                    printf("%d", i);
                }
                puts("");
            }
            for(int i = n-1; i >= 1; i--) {
                for(int j = i; j >= 1; j--) {
                    printf("%d", i);
                }
                puts("");
            }
            if(ts || r) puts("");
        }
    }
}
