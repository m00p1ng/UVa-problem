#include <cstdio>
#include <cmath>

int main() {
    int n;
    
    while (scanf("%d", &n), n != 0) {
        int sheets = ceil(n / 4.0);
        int page_left, page_right;

        printf("Printing order for %d pages:\n", n);

        if (n == 1) {
            puts("Sheet 1, front: Blank, 1"); 
            continue;
        }

        for (int i = 1; i <= sheets; i++) {
            page_left  = 4*sheets - 2*i + 2;
            page_right = 2*i - 1;

            printf("Sheet %d, front: ", i);
            if (page_left > n) {
                printf("Blank");
            } else {
                printf("%d", page_left);
            }
            printf(", %d\n", page_right);

            page_left  = 2*i;
            page_right = 4*sheets - 2*i + 1;

            printf("Sheet %d, back : ", i);
            printf("%d, ", page_left);
            if (page_right > n) {
                puts("Blank");
            } else {
                printf("%d\n", page_right);
            }
        }
    }
}
