#include <cstdio>

int main() {
    int ts;
    scanf("%d", &ts);

    int n;
    while(ts--) {
        scanf("%d", &n);
        
        int ans = (((((n*567)/9)+7492)*235)/47)-498;
        ans = ans / 10 % 10;
        ans = ans > 0 ? ans : -ans;
        printf("%d\n", ans);
    }
}
