#include <cstdio>
#include <cstring>

int main() {
    char num[10000];
    int skew;
    while(scanf("%s", num), strcmp(num, "0")) {
        skew = 0;
        int len = strlen(num);

        for(int i = 0; i < len; i++) {
            skew += (num[i]-'0')*((1<<(len-i))-1);
        }
        printf("%d\n", skew);
    }
}
