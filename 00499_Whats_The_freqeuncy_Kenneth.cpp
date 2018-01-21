#include <cstdio>
#include <cctype>
#include <cstring>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    char temp[100000];
    int cnt[256], m = 0;
    while(fgets(temp, 100000, stdin)) {
        memset(cnt, 0, sizeof(cnt));
        m = 0;
        for(int i = 0; i < strlen(temp); i++) {
            if(isalpha(temp[i])) {
                cnt[temp[i]]++;
                m = max(m, cnt[temp[i]]);
            }
        }
        
        if(m != 0) {
            for(int i = 'A'; i <= 'z'; i++) {
                if(cnt[i] == m) printf("%c", i);
            }
            printf(" %d\n", m);
        }
    }
}
