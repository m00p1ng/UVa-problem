#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    map<string, pair<int, string>> dict;
    vector<string> out;
    char s[100], ori[100];
    
    while(scanf("%s", s), s[0] != '#') {
        strcpy(ori, s);
        int len = strlen(s);

        for(int i = 0; i < strlen(s); i++)
            s[i] = tolower(s[i]);
        sort(s, s+len);

        if(dict[s].first == 0)
            dict[s].second = ori;
        dict[s].first++;
    }
    for(auto it = dict.begin(); it != dict.end(); ++it) {
        if(it->second.first == 1)
            out.push_back(it->second.second);
    }
    sort(out.begin(), out.end());
    for(auto it = out.begin(); it != out.end(); ++it) {
        printf("%s\n", (*it).c_str());
    }
}

