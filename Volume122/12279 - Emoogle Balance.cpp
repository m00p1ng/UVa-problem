#include <cstdio>

int main() {
    int n, sum, ts = 0, temp;
    while(scanf("%d", &n), n) {
        sum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &temp);
            if(temp == 0) sum--;
            else sum++;
        }
        printf("Case %d: %d\n", ++ts, sum);
    }
}
