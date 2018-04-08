#include <cstdio>

int main() {
    int a[5], b[5];
    while(scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]) == 5) {
        scanf("%d %d %d %d %d", &b[0], &b[1], &b[2], &b[3], &b[4]);
        bool result = true;
        for(int i = 0; i < 5; i++) result &= (a[i] ^ b[i]);
        if(result) puts("Y");
        else puts("N");
    }
}
