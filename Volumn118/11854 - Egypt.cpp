#include <cstdio>

bool is_triangle(int a, int b, int c) {
    if(a*a + b*b == c*c) return true;
    if(b*b + c*c == a*a) return true;
    if(c*c + a*a == b*b) return true;

    return false;
}

int main() {
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c), a || b || c) {
        if(is_triangle(a, b, c)) {
            puts("right");
        } else {
            puts("wrong");
        }
    }
}
