#include <cstdio>

int base16(int n) {
    int result = 0, con = 1;
    while(n > 0) {
        result +=  (n % 10)*con;
        n /= 10;
        con <<= 4;
    }
    return result;
}

int count1(int n) {
    int result = 0;
    while(n > 0) {
        result += n&1;
        n >>= 1;
    }
    return result;
}

int main() {
    int ts, n;
    int b1, b2;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d", &n);
        b1 = count1(n);
        b2 = count1(base16(n));
        printf("%d %d\n", b1, b2);
    }
}
