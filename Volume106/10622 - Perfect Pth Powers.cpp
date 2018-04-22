#include <cstdio>
#include <cmath>

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    while(scanf("%d", &n), n) {
        int flag = false;
        int p = 1;
        unsigned int abs_n = n > 0 ? n : -n;
        unsigned int temp = abs_n;
        int sq = sqrt(abs_n)+1;

        for(int i = 2; i <= sq && temp != 1; i++) {
            int cnt = 0;

            if(temp % i == 0) {
                while(temp % i == 0) {
                    cnt++;
                    temp /= i;
                }

                if(!flag) {
                    p = cnt;
                    flag = true;
                    continue;
                }

                p = gcd(p, cnt);
                if(p == 1) {
                    flag = false;
                    temp = abs_n;
                }
            }
        }
        if(temp != 1 && temp != abs_n) p = 1;
        if(n < 0 && p % 2 == 0) {
            while(p % 2 == 0) p /= 2;
        }
        printf("%d\n", p);
    }
}
