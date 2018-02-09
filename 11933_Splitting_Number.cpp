#include <cstdio>

int main() {
    int n;
    int a, b, s;
    bool trig;
    while(scanf("%d", &n), n) {
        a = b = 0;
        trig = true;

        for(int i = 0; i < 31; i++) {
            if((n>>i)&1) {
                if(trig) a += 1<<i;
                else b += 1<<i;
                trig = !trig;
            }
        }
        printf("%d %d\n", a, b);
    }
}
