#include <cstdio>
#include <cstring>

int main() {
    int n, temp;

    int odd_r, odd_c;
    int r[100], c[100];
    int flag;

    while(scanf("%d", &n), n) {
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &temp);
                r[i] += temp;
                c[j] += temp;
            }
        }
        
        flag = 0;
        odd_c = odd_r = -1;
        for(int i = 0; i < n; i++) {
            if(r[i] & 1) {
                odd_r = i;
                flag++;
            }
            if(c[i] & 1) {
                odd_c = i;
                flag++;
            }
        }

        if(flag == 0) {
            puts("OK");
        } else if(flag == 2 && odd_c != -1 && odd_r != -1) {
            printf("Change bit (%d,%d)\n", odd_r+1, odd_c+1);
        } else {
            puts("Corrupt");
        }
    }
}
