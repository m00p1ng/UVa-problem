#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string, string> pss;
vector<pss> word;

int idx = 0;

void print_word() {
    for(int i = 0; i < idx-1; i++) {
        for(int j = i+1; j < idx; j++) {
            if(word[i].second == word[j].second) {
                printf("%s", word[i].first.c_str());
                printf(" = ");
                printf("%s", word[j].first.c_str());
                puts("");
            }
        }
    }
}

bool cmp(pss a, pss b) {
    if(a.first < b.first) return true;
    return false;
}

string trim_space(char *s) {
    string temp = "";
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] != ' ') temp += s[i];
    }
    sort(temp.begin(), temp.end());
    return temp;
}

int main() {
    int testcase;
    scanf("%d\n", &testcase);
    char s[1000];

    while(testcase--) {
        while(fgets(s, 1000, stdin)) {
            if(strcmp(s, "\n") == 0) break;
            s[strlen(s)-1] = '\0';

            word.push_back(make_pair(s, trim_space(s)));
            idx++;
        }

        sort(word.begin(), word.end(), cmp);

        print_word();
        if(testcase) puts("");

        word.clear();
        idx = 0;
    }
}

