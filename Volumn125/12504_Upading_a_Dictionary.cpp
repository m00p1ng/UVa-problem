#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;

void print_set(set<string> s, char sign) {
    if(s.size()) {
        putchar(sign);
        auto it = s.begin();
        printf("%s", (*it).c_str());
        it++;
        for(; it != s.end(); ++it) {
            printf(",%s", (*it).c_str());
        }
        puts("");
    }
}

int main() {
    map<string, string> dict;
    set<string> pl, ch, rm;

    int testcase;
    const char token[] = "{:,}";
    scanf("%d\n", &testcase);
    while(testcase--) {
        dict.clear(); pl.clear(); ch.clear(); rm.clear();

        char p[200], n[200];
        fgets(p, 105, stdin); fgets(n, 105, stdin);
        p[strlen(p)-1] = n[strlen(n)-1] = '\0';

        char *tok;
        tok = strtok(p, token);
        while(tok != NULL) {
            char *tp;
            tp = tok;
            rm.insert(tp);
            tok = strtok(NULL, token);
            dict[tp] = tok;
            tok = strtok(NULL, token);
        }

        tok = strtok(n, token);
        while(tok != NULL) {
            char *tp, *tn;
            tp = tok;
            tok = strtok(NULL, token);
            if(dict[tp] == "") pl.insert(tp);
            else if(dict[tp] != tok) ch.insert(tp);
            rm.erase(tp);
            tok = strtok(NULL, token);
        }

        if(pl.size() || ch.size() || rm.size()) {
            print_set(pl, '+');
            print_set(rm, '-');
            print_set(ch, '*');
        }
        else puts("No changes");
        puts("");
    }
}
