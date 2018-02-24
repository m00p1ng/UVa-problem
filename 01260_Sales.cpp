#include <cstdio>

int main() {
    int ts;
    int n, data[1000], ans;
    scanf("%d", &ts);
    while(ts--) {
        ans = 0;
        scanf("%d", &n);
        scanf("%d", &data[0]);
        for(int i = 1; i < n; i++){
            scanf("%d", &data[i]);
            for(int j = 0; j < i; j++) {
                if(data[j] <= data[i]) ans++;
            }
        }
        printf("%d\n", ans);
    }
}
