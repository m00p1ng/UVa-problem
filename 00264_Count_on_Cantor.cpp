#include <cstdio>
#include <cmath>

int find_n(int a) {
    return (1.0+sqrt(1+8*a))/2.0; 
}

int main() {
    int n, r, ord, num;
    while(scanf("%d", &n) == 1) {
        r = find_n(n-1);
        ord = n - r*(r-1)/2;
        num = r - ord + 1; 

        printf("TERM %d IS ", n);
        if(r&1) printf("%d/%d\n", num, ord);
        else printf("%d/%d\n", ord, num);
    }
}
