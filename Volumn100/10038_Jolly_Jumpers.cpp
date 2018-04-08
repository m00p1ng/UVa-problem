#include <cstdio>
#include <cstring>

int abs(int n) {
    return n > 0 ? n : -n;
}

int main() {
    int n;
    int flag[3000];
    while(scanf("%d", &n) == 1) {
        memset(flag, 0, sizeof(flag));
       
        int prev, temp, diff;
        bool is_jolly = true;

        scanf("%d", &prev); 
        for(int i = 1; i < n; i++) {
            scanf("%d", &temp); 
            
            diff = abs(temp - prev);
            if(flag[diff] || diff > n-1 || diff < 1) {
                is_jolly = false;
            } else {
                flag[diff] = true;
            }

            prev = temp;
        }

        if(is_jolly) {
            puts("Jolly");
        } else {
            puts("Not jolly");
        }
    }
}
