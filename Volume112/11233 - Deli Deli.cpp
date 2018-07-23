#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

bool isvowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    map<string, string> dict;
    int d, w;
    scanf("%d %d", &d, &w);

    char f[1000], s[1000];
    for(int i = 0; i < d; i++) {
        scanf("%s %s", f, s);
        dict[f] = s;
    }

    for(int i = 0; i < w; i++) {
        scanf("%s", f);
        int len = strlen(f);

        if(dict[f] != "") {
            printf("%s\n", dict[f].c_str());
        } else {
            if(!isvowel(f[len-2]) && f[len-1] == 'y') {
                f[len-1] = 'i';
                printf("%ses\n", f);
            } else if(f[len-1] == 'o' || f[len-1] == 's' || f[len-1] == 'x' ||
                    ((f[len-2] == 'c' || f[len-2] == 's') && f[len-1] == 'h')) {
                printf("%ses\n", f);
            } else {
                printf("%ss\n", f);
            }
        }
    }
}
