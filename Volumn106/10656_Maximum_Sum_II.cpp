#include <cstdio>

int main() {
    int n, k;
    bool is_zero;
    while(scanf("%d", &n), n) {
        is_zero = true;
        for(int i = 0; i < n; i++) {
            scanf("%d", &k);
            if(k > 0) {
                if(is_zero) is_zero = false;
                else printf(" ");
                printf("%d", k); 
            }
        }
        if(is_zero) printf("0");
        puts("");
    }
}
