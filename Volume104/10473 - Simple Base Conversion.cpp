#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
    char buff[200];
    while(scanf("%s", buff), buff[0] != '-') {
        if(strlen(buff) > 2 && buff[0] == '0' && buff[1] == 'x') {
            printf("%ld\n", strtol(buff, NULL, 16));
        }
        else {
            printf("0x%X\n", atoi(buff));
        }
    }
}

