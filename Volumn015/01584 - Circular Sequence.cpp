#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        char buff[1000];
        scanf("%s", buff);
        string out = buff;
        string t = out;

        for(int i = 0; i < strlen(buff); i++) {
            char c = t[0];
            t.erase(t.begin());
            t += c;
            if(t < out) out = t;
        }
        puts(out.c_str());
    }
}

