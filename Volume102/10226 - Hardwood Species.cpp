#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int main() {
    int ts, cnt;
    char buff[40];
    double frac;
    map<string, int> tree;
    scanf("%d\n\n", &ts);

    while(ts--) {
        tree.clear();
        cnt = 0;

        while(fgets(buff, 35, stdin) && strcmp(buff, "\n")) {
            buff[strlen(buff)-1] = '\0';
            tree[buff]++;
            cnt++;
        }

        frac = 100.0/cnt;
        for(auto it = tree.begin(); it != tree.end(); it++) {
            printf("%s %.4f\n", it->first.c_str(), (it->second)*frac);
        }
        if(ts) puts("");
    }
}

