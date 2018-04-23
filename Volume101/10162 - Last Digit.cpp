#include <cstdio>
#include <cstring>

int ld[] = { 1, 5, 2, 8, 3, 9, 2, 8, 7, 7, 8, 4, 7, 3, 8, 4, 1, 5, 4, 4 };

int main() {
    char input[1000];
    while(scanf("%s", input), input[0] != '0') {
        int len, last;
        len = strlen(input);
        last = input[len-1] - '0' - 1;

        if(len >= 2) last += (input[len-2]-'0')*10;
        if(len >= 3) last += (input[len-3]-'0')*100;
        int d = 4*(last/20) + ld[(last % 20)];
        printf("%d\n", d % 10);
    }
}
