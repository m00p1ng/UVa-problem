#include <cstdio>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int ts;
    int m;
    char web[10][10000];
    int score[10];
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        m = 0;

        for(int i = 0; i < 10; i++) {
            scanf("%s %d", web[i],  &score[i]);
            m = max(m, score[i]);
        }
        

        printf("Case #%d:\n", t);
        for(int i = 0; i < 10; i++) {
            if(score[i] == m) {
                puts(web[i]);
            }
        }
    }
}
