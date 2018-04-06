#include <cstdio>
#include <cstring>

enum {ax, ay, az, bx, by, bz};

int main() {
    int n, cur;
    char temp[10];
    while(scanf("%d", &n), n) {
        cur = ax;
        
        for(int i = 0; i < n-1; i++) {
            scanf("%s", temp);
            if(temp[0] == 'N') continue;

            if(!strcmp(temp, "+y")) {
                if(cur == ax) cur = ay;
                else if(cur == bx) cur = by;
                else if(cur == ay) cur = bx;
                else if(cur == by) cur = ax;
            } else if(!strcmp(temp, "-y")) {
                if(cur == ax) cur = by;
                else if(cur == bx) cur = ay;
                else if(cur == ay) cur = ax;
                else if(cur == by) cur = bx;
            } else if(!strcmp(temp, "+z")) {
                if(cur == ax) cur = az;
                else if(cur == bx) cur = bz;
                else if(cur == az) cur = bx;
                else if(cur == bz) cur = ax;
            } else if(!strcmp(temp, "-z")) {
                if(cur == ax) cur = bz;
                else if(cur == bx) cur = az;
                else if(cur == az) cur = ax;
                else if(cur == bz) cur = bx;
            }
        }

        if(cur % 6 < 3) printf("+");
        else printf("-");

        if(cur % 3 == 0) puts("x");
        else if(cur % 3 == 1) puts("y");
        else puts("z");
    }
}
