#include <cstdio>
#include <cctype>
#include <cstring>
#include <queue>
using namespace std;

int main() {
    int len, cnt[26] = {0};
    char temp[100000];
    priority_queue<pair<int, int>> pq;
    pair<int, int> t;

    scanf("%*d");

    while(scanf("%s", temp) == 1) {
        len = strlen(temp);
        for(int i = 0; i < len; i++) {
            if(isalpha(temp[i])) {
                cnt[toupper(temp[i]) - 'A']++;
            }
        }
    }

    for(int i = 0; i < 26; i++) {
        if(cnt[i] > 0) {
            pq.push(make_pair(cnt[i], -i));
        }
    }

    while(!pq.empty()) {
        t = pq.top(); pq.pop();
        printf("%c %d\n", 'A'-t.second, t.first);
    }
}
