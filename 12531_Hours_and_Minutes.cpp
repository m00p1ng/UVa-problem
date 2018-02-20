#include <cstdio>

int main() {
    int degree;
    while(scanf("%d", &degree) == 1) {
        if(degree % 6 == 0) puts("Y");
        else puts("N");
    }
}

