#include <cstdio>

int humble[6000];

int min(int a, int b) {
    return a < b ? a : b;
}

void gen_humble() {
    humble[0] = 0;
    humble[1] = 1;

    int idx = 2;

    int i2 = 1, i3 = 1, i5 = 1, i7 = 1;
    int n2 = 2, n3 = 3, n5 = 5, n7 = 7;
    while(idx <= 5842) {
        int val = min(min(n2, n3), min(n5, n7));
        humble[idx++] = val;
        if(val == n2) { i2++; n2 = humble[i2]*2; }
        if(val == n3) { i3++; n3 = humble[i3]*3; }
        if(val == n5) { i5++; n5 = humble[i5]*5; }
        if(val == n7) { i7++; n7 = humble[i7]*7; }
    }
}

int main() {
    gen_humble();
    int n;
    while(scanf("%d", &n), n) {
        printf("The %d", n);
        if(n % 100 == 11 || n % 100 == 12 || n % 100 == 13) printf("th");
        else if(n % 10 == 1) printf("st");
        else if(n % 10 == 2) printf("nd");
        else if(n % 10 == 3) printf("rd");
        else printf("th");
        printf(" humble number is %d.\n", humble[n]);
    }
}

