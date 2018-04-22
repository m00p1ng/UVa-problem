#include <cstdio>
#include <cstring>
int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    int freq[26];
    int cnt, m;
    char pizza[1000];

    while(n--) {
        cnt = 0;
        m = 1e6;
        memset(freq, 0, sizeof(freq));

        scanf("%s",  pizza);
        for(int i = 0; i < strlen(pizza); i++) {
            freq[pizza[i]-'A']++;
        }
        
        m = min(m, freq['M'-'A']);
        m = min(m, freq['A'-'A']/3);
        m = min(m, freq['R'-'A']/2);
        m = min(m, freq['G'-'A']);
        m = min(m, freq['I'-'A']);
        m = min(m, freq['T'-'A']);
        printf("%d\n", m);
    }
}
