#include <cstdio>

int main() {
    int ts;
    scanf("%d", &ts);

    for(int t = 1; t <= ts; t++) {
        bool solve = true;
        int n;
        for(int i = 0; i < 13; i++) {
            scanf("%d", &n);
            solve &= n != 0;
        }
        printf("Set #%d: ", t);
        if(solve) puts("Yes");
        else puts("No");
    }
}
