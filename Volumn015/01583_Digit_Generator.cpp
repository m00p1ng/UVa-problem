#include <cstdio>

int main() {
    int ts, n, sum, temp;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d", &n);
        int out = 0;

        for(int i = n-55; i < n; i++) {
            temp = sum = i;

            while(temp) {
                sum += temp % 10;
                temp /= 10;
            }
            if(sum == n) {
                out = i;
                break;
            }
        }
        printf("%d\n", out);
    }
}
