#include <cstdio>

int main() {
    int p, h, o;
    while(scanf("%d %d %d", &p, &h, &o) == 3) {
        int remain = o - h;

        if (remain < p) {
            puts("Hunters win!");
        } else {
            puts("Props win!");
        }
    }
}
