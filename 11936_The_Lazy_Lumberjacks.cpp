#include <cstdio>

int main() {
    int ts;
    int a, b, c;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d %d %d", &a, &b, &c);
        if(a+b <= c || b+c <= a || c+a <= b) puts("Wrong!!");
        else puts("OK");
    }
}
