#include <cstdio>
#include <cstring>

int main() {
    char num[1000010];
    while(scanf("%s", num), num[0] != 'E') {
        int p, n, cnt;
        n = strlen(num);
        
        cnt = 1;
        if(n == 1 && num[0] > '1') cnt++;

        while(p != n) {
            p = n;
            sprintf(num, "%d", n);
            n = strlen(num);

            cnt++;
        }
        printf("%d\n", cnt);
    }
}
