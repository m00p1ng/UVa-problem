#include <cstdio>

int abs(int n) {
    return n > 0 ? n : -n;
}

void print_first(int num, int deg) {
    if(num < 0) printf("-");

    if(abs(num) > 1) printf("%d", abs(num));
    else if(deg == 0) printf("%d", abs(num));

    if(abs(num) >= 1 && deg > 1) printf("x^%d", deg);
    else if(deg == 1) printf("x");
}

void print_coff(int num, int deg) {
    if(num < 0) printf(" - ");
    else printf(" + ");

    if(abs(num) > 1) printf("%d", abs(num));
    else if(abs(num) == 1 && deg == 0) printf("1");

    if(deg > 1) printf("x^%d", deg);
    else if(deg == 1) printf("x");
}

int main() {
    int num;
    int deg = 8;
    int is_first = true;

    do {
        if(scanf("%d", &num) == 1) {
            if(deg == -1) {
                puts("");
                deg = 8;
                is_first = true;
            }
            if(num != 0) {
                if(is_first) {
                    print_first(num, deg);
                    is_first = false;
                } else print_coff(num, deg);
            }
            if(is_first && deg == 0 && num == 0) printf("0"); 
            deg--;
        } else break; 
    } while(1);
    puts("");
}
