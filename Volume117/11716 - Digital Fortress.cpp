#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
    char s[10010];
    int ts;
    scanf("%d\n", &ts);

    int len, sq;
    while(ts--) {
        fgets(s, 10010, stdin);
        len = strlen(s)-1;
        sq = sqrt(len);
        if(len - sq*sq != 0) {
            puts("INVALID");
        } else {
            for(int i = 0; i < sq; i++) {
                for(int j = 0; j < sq; j++) {
                    printf("%c", s[i+sq*j]);
                }
            }
            puts("");
        }
    }
}
