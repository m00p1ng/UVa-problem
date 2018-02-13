#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> dict;

    char buff[1000];
    char a[100], b[100];
    int idx, s;
    while(fgets(buff, 1000, stdin), buff[0] != '\n') {
        sscanf(buff, "%s %s\n", a, b);
        dict[a] = b;
        dict[b] = a;
    }
    while(scanf("%s", buff) == 1) {
        if(dict[buff] != "") puts(dict[buff].c_str());
        else puts("eh");
    }
}
