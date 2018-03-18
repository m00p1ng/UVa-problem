#include <cstdio>

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int main() {
    int frac;
    while(scanf("%d", &frac) == 1) {
        int fracTable[10000][2];
        int cnt = 0;
        for(int i = frac + 1; i <= 2*frac; i++) {
            int up = i - frac;
            int down = i*frac;

            int divide = gcd(up, down);
            if(divide != 1) {
                up /= divide;
                down /= divide;
            }
            if(up == 1) {
                fracTable[cnt][0] = down;
                fracTable[cnt][1] = i;
                cnt++;
            }
        }
        printf("%d\n", cnt);
        for(int i = 0; i < cnt; i++) {
            printf("1/%d = 1/%d + 1/%d\n", frac, fracTable[i][0], fracTable[i][1]);
        }
    }
}

