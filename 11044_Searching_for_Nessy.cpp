#include <cstdio>

int main() {
    int ts;
    scanf("%d", &ts);

    while(ts--) {
        int n, m;
        scanf("%d %d", &n, &m);

        n /= 3;
        m /= 3;

        printf("%d\n", n*m);
    }
}
