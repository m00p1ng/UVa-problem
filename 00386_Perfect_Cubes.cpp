#include <cstdio>

int main() {
    int p[201];
    for(int a = 2; a <= 200; a++) {
        p[a] = a*a*a;
        for(int b = 2; b <= a; b++) {
            for(int c = b+1; c <= a; c++) {
                for(int d = c+1; d <= a; d++) {
                    if(p[a] == p[b] + p[c] + p[d]) {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                    }
                }
            }
        }
    }
}
