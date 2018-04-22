#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    int n;
    string num[100];
    char buff[100];
    while(scanf("%d", &n), n) {
        for(int i = 0; i < n; i++) {
            scanf("%s", buff);
            num[i] = buff;
        }
        sort(num, num+n, cmp);
        for(int i = 0; i < n; i++) {
            printf("%s", num[i].c_str());
        }
        puts("");
    }
}
