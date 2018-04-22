#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, string> is;

bool cmp(is a, is b) {
    if(a.first > b.first) return true;
    return false;
}

int main(){
    int testcase;
    char name[100], p[100];
    map<string, is> party;
    vector<pair<int, string>> score;

    scanf("%d\n", &testcase);
    while(testcase--) {
        party.clear();
        score.clear();
        int n;

        scanf("%d\n", &n);
        for(int i = 0; i < n; i++) {
            fgets(name, 100, stdin); name[strlen(name)-1] = '\0';
            fgets(p, 100, stdin); p[strlen(p)-1] = '\0';
            party[name].second = p;
        }

        scanf("%d\n", &n);
        for(int i = 0; i < n; i++) {
            fgets(name, 100, stdin); name[strlen(name)-1] = '\0';
            party[name].first++;
        }
        
        for(auto it = party.begin(); it != party.end(); ++it) {
            if(it->second.second == "") continue;
            score.push_back(make_pair(it->second.first, it->second.second));
        }

        sort(score.begin(), score.end(), cmp);

        if(score.size() > 1 && score[0].first == score[1].first) {
            puts("tie");
        } else {
            puts(score[0].second.c_str());
        }
        if(testcase) puts("");
    }
}

