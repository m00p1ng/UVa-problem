#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int ts, n;
    char s[100], ori[100];
    scanf("%d", &ts);
    vector<pair<string, string>> word;

    while(ts--) {
        word.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            strcpy(ori, s);
            sort(s, s+strlen(s));
            word.push_back(make_pair(s, ori));
        }

        while(scanf("%s", s), strcmp(s, "END")) {
            int cnt = 0;
            strcpy(ori, s);
            printf("Anagrams for: %s\n", ori);
            for(int i = 0; i < word.size(); i++) {
                sort(s, s+strlen(s));
                if(!strcmp(word[i].first.c_str(), s)) {
                    cnt++;
                    printf("%3d) %s\n", cnt, word[i].second.c_str());
                }
            }
            if(cnt == 0) printf("No anagrams for: %s\n", ori);
        }
        if(ts) puts("");
    }
}

