#include <cstdio>

int main() {
    int ts, round;
    char c;

    scanf("%d", &ts);
    
    for (int t = 1; t <= ts; t++) {
        scanf("%d\n", &round);

        int leave = 0;
        int last_win = 0;

        for (int i = 1; i <= round; i++) {
            scanf("%c\n", &c);

            if (c == 'W') {
                last_win = i;
            }

            if (i - last_win == 3 && leave == 0) {
                leave = i;
            }
        }

        printf("Case %d: ", t);
        if (leave != 0) {
            printf("%d\n", leave);
        } else {
            puts("Yay! Mighty Rafa persists!");
        }
    }
}
