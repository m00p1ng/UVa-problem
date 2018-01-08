#include <cstdio>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int ts;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        int n;
        scanf("%d", &n);
        int req = 0;
        int temp;
        
        for(int i = 0; i < n; i++) {
            scanf("%d", &temp);
            req = max(req, temp);
        }
        printf("Case %d: %d\n", t, req);
    }
}
