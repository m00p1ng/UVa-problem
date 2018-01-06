#include <cstdio>
#include <cstring>

int main() {
    char temp[1000];
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%s", temp);
        int len = strlen(temp);

        if(!strcmp(temp, "1") || !strcmp(temp, "4") || !strcmp(temp, "78")) {
            puts("+");
        } else if(temp[len-2] == '3' && temp[len-1] == '5') {
            puts("-");
        } else if(temp[0] == '9' && temp[len-1] == '4') {
            puts("*");
        } else if(temp[0] == '1' && temp[1] == '9' && temp[2] == '0') {
            puts("?");
        }
    }
}
