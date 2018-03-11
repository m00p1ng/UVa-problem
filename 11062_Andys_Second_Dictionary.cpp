#include <cstdio>
#include <set>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
    char buff[10000];
    set<string> dict;

    string temp = ""; 
    while(scanf("%s", buff) == 1) {
        int len = strlen(buff);
        for(int i = 0; i < len; i++) {
            if(isalpha(buff[i]) || buff[i] == '-') {
                temp += tolower(buff[i]);
            } else {
                dict.insert(temp);
                temp = "";
            }

        }
        if(buff[len-1] == '-') {
            temp.pop_back();
        } else {
            dict.insert(temp);
            temp = "";
        }
    }

    for(auto it = dict.begin(); it != dict.end(); ++it) {
        if(*it != "") printf("%s\n", (*it).c_str());
    }
}

