#include <cstdio>

int catalan[11] = {0};

void gen_catalan() {
    catalan[0] = catalan[1] = 1;
    for(int n = 2; n <= 10; n++) {
        for(int i = 0; i < n; i++) {
            catalan[n] += catalan[i] * catalan[n-i-1];
        }
    }
}

int main() {
    gen_catalan();
    int n;
    bool ts = false;

    while(scanf("%d", &n) == 1) {
        if(ts) puts("");
        ts = true;
        printf("%d\n", catalan[n]);
    }
}


