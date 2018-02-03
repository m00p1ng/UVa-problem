#include <cstdio>

int abs(int n) {
    return n > 0 ? n : -n;
}

int main() {
    int xi, yi, xj, yj;
    while(scanf("%d %d %d %d", &xi, &yi, &xj, &yj), xi || yi || xj || yj) {
        int dx = abs(xi-xj);
        int dy = abs(yi-yj);
        if(xi == xj && yi == yj) puts("0");
        else if(xi == xj || yi == yj || dx == dy) puts("1");
        else puts("2");
    }
}
