#include <cstdio>
#include <cstring>

int main() {
    int ts;
    char s[100];
    scanf("%d", &ts);

    while(ts--) {
        scanf("%s", s);
        int len = strlen(s);
        int idx = len;

        for(int i = 1; i <= len/2; i++) {
            if(len % i == 0) {
                int per_cnt = 0;
                for(int j = i; i+j <= len; j+=i) {
                    int temp_cnt = 0;
                    for(int k = 0; k < i; k++) {
                        if(s[k] == s[j+k]) temp_cnt++;
                        else break;
                    }
                    if(temp_cnt == i) per_cnt++;
                    else break;
                }
                if(per_cnt+1 == len/i) {
                    idx = i;
                    break;
                }
            }
        }
        printf("%d\n", idx);
        if(ts) puts("");
    }
}
