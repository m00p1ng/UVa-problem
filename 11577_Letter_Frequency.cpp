#include <cstdio>
#include <cstring>
#include <cctype>

int main() {
    int ts;
    char s[10000], c;
    int freq[128], max;
    scanf("%d\n", &ts);
    while(ts--) {
        fgets(s, 10000, stdin);
        max = 0;
        memset(freq, 0, sizeof(freq));
        int len = strlen(s)-1;

        for(int i = 0; i < len; i++) {
            c = tolower(s[i]);
            if(isalpha(c)) freq[c]++;
            if(freq[c] > max) max = freq[c];
        }
        for(int i = 33; i < 128; i++) {
            if(freq[i] == max) printf("%c", i);
        }
        puts("");
    }
}
