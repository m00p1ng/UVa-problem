#include <cstdio>

int abs(int n) {
    return n > 0 ? n : -n;
}

int main() {
    int ts;
    scanf("%d", &ts);

    while(ts--) {
        int n;
        scanf("%d", &n);

        int a, b;
        scanf("%d %d", &a, &b);
        bool no_island = true;

        int diff = abs(a-b); 

        for(int i = 1; i < n; i++) {
            scanf("%d %d", &a, &b);
            if(diff != abs(a-b)) {
                no_island = false;
            }
        }

        if(no_island) puts("yes");
        else puts("no");
        if(ts) puts("");
    }
}
