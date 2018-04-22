#include <cstdio>

int main() {
    int testcase;
    int x1, y1, x2, y2, cx, cy, r;

    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &cx, &cy, &r);

        int xdiff = x2-x1;
        int ydiff = y2-y1;

        bool is_flag = true;

        if(100*x1+45*xdiff != 100*cx || ydiff != 2*(cy-y1)) is_flag = false;
        if(6*xdiff != 10*ydiff) is_flag = false;
        if(6*r != 2*ydiff) is_flag = false;

        puts(is_flag ? "YES" : "NO");
    }    
}

