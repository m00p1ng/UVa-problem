#include <cstdio>
#include <cmath>

int main() {
    int ts = 0;
    double n;
    while(scanf("%lf", &n), n) {
        int k = ceil((3 + sqrt(9 + 8*n))/2);
        printf("Case %d: %d\n", ++ts, k);
    }
}
