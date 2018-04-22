#include <cstdio>
#include <cstring>

int main() {
    char key[] = "01230120022455012623010202";

    char s[1000];
    char prev, next;
    while(scanf("%s", s) == 1) {
        int len = strlen(s);
        prev = key[s[0]-'A'];
        if(prev != '0') putchar(prev);

        for(int i = 1; i < len; i++) {
            next = key[s[i]-'A'];
            if(next != '0' && prev != next) {
                putchar(next);
            }
            prev = next;
        }
        puts("");
    }
}
