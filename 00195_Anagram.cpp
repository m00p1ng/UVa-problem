#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;

bool cmp(char a, char b) {
    if(tolower(a) == tolower(b) && a < b) return true; 
    if(tolower(a) < tolower(b)) return true;
    return false;
}

int main() {
    int ts;
    char s[1000];
    scanf("%d", &ts);
    while(ts--) {
        scanf("%s", s);
        int len = strlen(s);
        sort(s, s+len, cmp);
        do {
            printf("%s\n", s);
        } while(next_permutation(s, s+len, cmp));
    }
}
