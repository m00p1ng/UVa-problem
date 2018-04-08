#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    char s[1000], ori[1000];
    vector<pair<string, string>> word;
    while(scanf("%s", s), strcmp(s, "XXXXXX")) {
        strcpy(ori, s);
        sort(s, s+strlen(s));
        word.push_back(make_pair(s, ori));
    }
    sort(word.begin(), word.end());
    while(scanf("%s", s), strcmp(s, "XXXXXX")) {
        strcpy(ori, s);
        sort(s, s+strlen(s));
        bool is_valid = false;
        for(int i = 0; i < word.size(); i++) {
            if(!strcmp(word[i].first.c_str(), s)) {
                puts(word[i].second.c_str());
                is_valid |= 1;
            }
        }
        if(!is_valid) puts("NOT A VALID WORD");
        puts("******");
    }
}

