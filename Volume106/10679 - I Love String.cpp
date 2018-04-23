#include <cstdio>
#include <cstring>
using namespace std;

int kmp_table[1100], len_p, len_s;

void KMPPreprocess(char* p) {
    int i = 0, j = -1; kmp_table[0] = -1;
    while (i < len_p) {
        while (j >= 0 && p[i] != p[j]) j = kmp_table[j];
        i++; j++;
        kmp_table[i] = j;
    }
}

bool KMPSearch(char* s, char* p) {
    int i = 0, j = 0;
    while (i < len_s) {
        while (j >= 0 && s[i] != p[j]) j = kmp_table[j];
        i++; j++;
        if (j == len_p) return true;
    }
    return false;
}

int main() {
    int q, ts;
    char s[100100], p[1100];
    scanf("%d", &ts);
    while(ts--) {
        scanf("%s", s);
        scanf("%d", &q);
        len_s = strlen(s);

        while(q--) {
            scanf("%s", p);
            len_p = strlen(p);

            KMPPreprocess(p);
            if(KMPSearch(s, p)) puts("y");
            else puts("n");
        }
    }
}

