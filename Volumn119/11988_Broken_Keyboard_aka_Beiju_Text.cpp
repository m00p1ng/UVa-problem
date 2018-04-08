#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

int main() {
    char s[100001];
    while(scanf("%s", s) == 1) {
        list<char> out;
        list<char>::iterator it = out.begin();
        int len = strlen(s);

        for(int i = 0; i < len; i++) {
            if(s[i] == '[') it = out.begin();
            else if(s[i] == ']') it = out.end();
            else out.insert(it, s[i]);
        }

        for(it = out.begin(); it != out.end(); it++) {
            printf("%c", *it);
        }
        puts("");
    }
}

