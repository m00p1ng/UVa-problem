#include <cstdio>

int main() {
    int a, b, m, cnt, j;
    while(scanf("%d %d", &a, &b) == 2) {
        m = 0;

        printf("%d %d", a, b);
        if(a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        for(int i = a; i <= b; i++) {
            cnt = 1;
            j = i;
            while(j > 1) {
                if(j & 1) j = 3*j+1;
                else j = j/2;
                cnt++;
            }
            if(cnt > m) m = cnt;
        }
        printf(" %d\n", m);
    }
}

