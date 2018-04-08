#include <cstdio>

int main() {
    int n;
    int ts = 0;
    int data[20];
    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; i++) scanf("%d", &data[i]); 
        long long max = ~0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                long long product = 1;
                for(int k = i; k <= j; k++) {
                    product *= data[k];
                    if(product > max) max = product;
                }
            }
        }
        if(max < 0) max = 0;
        printf("Case #%d: The maximum product is %lld.\n\n", ++ts, max);
    }
}
