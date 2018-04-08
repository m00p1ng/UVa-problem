#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    map<string, int> dict;
    scanf("%d", &n);
    while(n--) {
        char temp[100];
        scanf("%s", temp);
        dict[temp]++;
        fgets(temp, 100, stdin);
    }
    for(auto it = dict.begin(); it != dict.end(); it++) {
        printf("%s %d\n", it->first.c_str(), it->second);
    }
}

