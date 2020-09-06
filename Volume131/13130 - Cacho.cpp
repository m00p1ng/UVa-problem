#include <cstdio>

int main() {
    int ts;
    int a[5];

    scanf("%d", &ts);
    while(ts--) {
        scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);

        bool is_escala_1 = a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5;
        bool is_escala_2 = a[0] == 2 && a[1] == 3 && a[2] == 4 && a[3] == 5 && a[4] == 6;

        if(is_escala_1 || is_escala_2) {
            puts("Y");
        } else {
            puts("N");
        }
    }
}
