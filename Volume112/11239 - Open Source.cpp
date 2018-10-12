#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, string> is;

int main() {
    char s[1000], proj_name[1000], prev_cmd[1000];
    map<string, string> dict;
    map<string, int> cnt;

    while(true) {
        if(strcmp(s, "0\n") == 0) {
            break;
        }
        dict.clear();
        cnt.clear();

        while(fgets(s, 1000, stdin), strcmp(s, "1\n") && strcmp(s, "0\n")) {
            s[strlen(s)-1] = '\0'; 

            if(isupper(s[0])) {
                strcpy(proj_name, s);
                cnt[proj_name] = 0;
            } else {
                if(dict[s] == "") {
                    dict[s] = proj_name;
                    cnt[proj_name]++;
                } else if(dict[s] != proj_name && cnt[dict[s]]) {
                    cnt[dict[s]]--;
                    dict[s] = "-";
                }
            }
        }

        vector<is> temp;
        for(auto it : cnt) {
            if(it.first == "-") continue;
            temp.push_back(is(-it.second, it.first));
        }
        sort(temp.begin(), temp.end());


        for(auto it : temp) {
            printf("%s %d\n", it.second.c_str(), -it.first);
        }
    }
}
