#include <cstdio>
#include <cstring>

int main() {
    int ts, len;
    char n[1010];
    scanf("%d", &ts);
    while(ts--) {
        scanf("%s", n);
        len = strlen(n);
        if(len == 1 && n[0] == '0') puts("1");
        else if(len == 1 && n[0] == '1') puts("66");
        else {
            int k = n[len-1] % 5;
            if(k == 0) puts("56");
            else if(k == 1) puts("96");
            else if(k == 2) puts("36");
            else if(k == 3) puts("76");
            else if(k == 4) puts("16");
        }
    }
}
