#include <cstdio>
#include <cstring>
#include <cctype>

int main() {
    char buff[100];
    int freq[31] = {0};
    int flag = false;
    int sz = 0;
    while(scanf("%s", buff) == 1) {
        if(buff[0] == '#') {
            for(int i = 1; i <= 30; i++) {
                if(freq[i]) {
                    printf("%d %d\n", i, freq[i]);
                }
            }
            puts("");
            memset(freq, 0, sizeof freq);
        } else {
            int len = strlen(buff);
            if(!flag) sz = 0;
            for(int i = 0; i < len; i++) {
                if(isalpha(buff[i])) sz++;
                else if(buff[i] == '\'' || buff[i] == '-') continue;
                else {
                    freq[sz]++;
                    sz = 0;
                }
            }
            if(buff[len-1] == '\'' || buff[len-1] == '-') {
                flag = true;
                continue;
            }
            flag = false;
            freq[sz]++;
        }
    }
}

