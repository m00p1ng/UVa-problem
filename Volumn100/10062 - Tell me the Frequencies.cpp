#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main() {
    char s[1010];
    int freq[200];
    priority_queue<pair<int,int>> pq;

    int cnt = 0;
    while(fgets(s, 1010, stdin)) {
        if(cnt != 0) puts("");
        cnt++;
        memset(freq, 0, sizeof(freq));
        int len = strlen(s)-1;
        for(int i = 0; i < len; i++) {
            freq[s[i]]++;
        }
        for(int i = 32; i < 128; i++) {
            if(freq[i] != 0) {
                pq.push(make_pair(-freq[i], i));
            }
        }
        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            printf("%d %d\n", p.second, -p.first);
        }
    }
}
