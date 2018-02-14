#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int ts, len;
    char s[100];
    scanf("%d", &ts);
    while(ts--) {
        scanf("%s", s);
        len = strlen(s);
        sort(s, s+len);
        do {
            puts(s);
        } while(next_permutation(s, s+len));
        puts("");
    }
}
