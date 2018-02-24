#include <cstdio>
int abs(int a) {
    return a > 0 ? a : -a;
}

int main() {
    int ch, cm, ah, am;
    while(scanf("%d %d %d %d", &ch, &cm, &ah, &am), ch || cm || ah || am) {
        int hour, minute;
        if(am < cm) {
            ah--;
            am += 60;
        }
        minute = abs(am-cm);

        hour = ah - ch;
        if(ah < ch) hour += 24;
        printf("%d\n", minute + 60*hour);
    }
}

