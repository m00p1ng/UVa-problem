#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>

int main() {
    int ts;
    scanf("%d\n", &ts);
    char s[100];
    int data[10000];
    int dp[10000] = {0};
    int pos[10000] = {0};
    std::stack<int> out;

    while(ts--) {
        int max, idx, cnt;
        max = idx = cnt = 0;

        while(fgets(s, 100, stdin)) {
            if(strcmp(s, "\n")) {
                cnt++;
                int num = atoi(s);
                data[cnt] = num;
                int curmax = 0;
                for(int i = 1; i < cnt; i++) {
                    if(num > data[i] && dp[i] > curmax) {
                        curmax = dp[i];
                        pos[cnt] = i;
                    }
                }
                dp[cnt] = curmax+1;
                if(dp[cnt] > max) {
                    max = dp[cnt];
                    idx = cnt;
                }
            }
            else break;
        }
        out.push(data[idx]);
        idx = pos[idx];

        while(idx) {
            out.push(data[idx]);
            idx = pos[idx];
        }

        printf("Max hits: %d\n", max);
        while(!out.empty()) {
            printf("%d\n", out.top());
            out.pop();
        }

        if(ts) puts("");
    }
}

