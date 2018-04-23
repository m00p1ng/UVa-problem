#include <cstdio>
#include <cstring>

int main() {
    char s[1000010];
    while(scanf("%s", s), s[0] != '.') {
        int len = strlen(s);
        int cnt = 0;

        int i = 1;
        while(i <= len/2) {
            if(len % i == 0) {
                int per_cnt = 0;
                for(int j = i; i+j <= len; j+=i) {
                    int temp_cnt = 0;
                    for(int k = 0; k < i; k++) {
                        if(s[k] == s[j+k]) temp_cnt++;
                        else break;
                    }
                    if(temp_cnt == i) per_cnt++;
                    else {
                        i = j;
                        break;
                    }
                }
                if(per_cnt+1 == len/i) {
                    cnt = per_cnt;
                    break;
                }
            }
            i++;
        }

        printf("%d\n", cnt+1);
    }
}
