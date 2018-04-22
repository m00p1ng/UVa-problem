#include <cstdio>

int main() {
    char temp[20];
    int cnt = 0;
    while(scanf("%s", temp), temp[0] != '*') {
        printf("Case %d: Hajj-e-", ++cnt);
        if(temp[0] == 'H') puts("Akbar");
        else puts("Asghar");
    }
}
