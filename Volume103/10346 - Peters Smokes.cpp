#include <cstdio>

int main() {
    int smoke, n;
    while(scanf("%d %d", &smoke, &n) == 2) {
        int sum = smoke;

        while(smoke/n) {
            sum += smoke/n;
            smoke = smoke/n + smoke%n;
        }
        printf("%d\n", sum);
    }
}
