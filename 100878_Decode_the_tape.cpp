#include <cstdio>
#include <cstring>

int main() {
    char s[100];
    scanf("%*s\n");
    while(fgets(s, 100, stdin), s[0] != '_') {
        int sum = 0;
        for(int i = 2; i < 10; i++) {
            if(i == 6) continue;
            sum = (sum << 1) + (s[i] == 'o');
        }
        printf("%c", sum);
    }
}
