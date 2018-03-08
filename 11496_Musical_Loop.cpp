#include <cstdio>

int main() {
    int loop;
    while(scanf("%d", &loop), loop) {
        int f, be, af;
        scanf("%d %d", &be, &af);
        f = be;
        
        bool is_minus = be - af < 0;
        bool f_is_minus = is_minus;
        int count = 1;

        be = af;

        for(int i = 2; i < loop; i++) {
            scanf("%d", &af);
            if((is_minus && be - af > 0) || (!is_minus && be - af < 0)) {
                count++;
                is_minus = !is_minus;
            }
            be = af;
        }

        bool l_is_minus = af - f < 0;
        if(f_is_minus == !l_is_minus && is_minus == !l_is_minus) count++;
        else if(f_is_minus == l_is_minus && is_minus == l_is_minus) count--;
        
        printf("%d\n", count);
    }
}

