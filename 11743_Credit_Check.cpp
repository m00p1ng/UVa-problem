#include <cstdio>

int d_root(int n) {
    if(n == 0) return 0;
    int a = n % 9;

    if(a == 0) return 9;
    return a;
}

int main() {
    int ts;
    char t[10];
    scanf("%d", &ts);
    int even, odd;

    while(ts--) {
        even = odd = 0;
        for(int i = 0; i < 4; i++) {
            scanf("%s", t);
            even += d_root(2*(t[0]-'0')) + d_root(2*(t[2]-'0'));
            odd += (t[1] + t[3] - 2*'0');
        }
        
        if((odd + even) % 10 == 0) puts("Valid");
        else puts("Invalid");
    }
}
