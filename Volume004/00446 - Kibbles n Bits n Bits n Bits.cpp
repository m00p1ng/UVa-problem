#include <cstdio>

int main() {
    int n, a, b;
    char c;
    scanf("%d", &n);

    while(n--) {
        scanf("%X %c %X", &a, &c, &b);

        int result = c == '+' ? a + b : a - b;
        for(int i = 12; i >= 0; i--) printf("%d", (a>>i) & 1);
        printf(" %c ", c);
        for(int i = 12; i >= 0; i--) printf("%d", (b>>i) & 1);
        printf(" = %d\n", result);
    }
}
