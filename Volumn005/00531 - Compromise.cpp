#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <stack>
using namespace std;

int a[110], b[110];
char dict[250][40];
int dp[110][110] = {0};
int la, lb, ld;

int max(int a, int b) {
    return a > b ? a : b;
}

void calc_dp() {
    for(int i = 1; i <= la; i++) {
        for(int j = 1; j <= lb; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
}

void print_dp() {
    stack<int> s;

    int i = la, j = lb;
    int m = dp[la][lb];

    while(m) {
        if(dp[i][j-1] < m && dp[i-1][j] < m) {
            s.push(a[i]);
            m--;
            i--;
            j--;
        }
        else if(dp[i][j-1] == m) j--;
        else if(dp[i-1][j] == m) i--;
    }

    if(!s.empty()) {
        printf("%s", dict[s.top()]);
        s.pop();
        while(!s.empty()) {
            printf(" %s", dict[s.top()]);
            s.pop();
        }
    }
    puts("");
}

int main() {
    char temp[100]; 
    int cnt;
    map<string, int> m;
    bool valid = true;

    while(valid) {
        m.clear();
        la = lb = ld = cnt = 1;

        valid = false;
        while(scanf("%s", temp) == 1 && temp[0] != '#') {
            if(m[temp] == 0) {
                m[temp] = cnt++;
                strcpy(dict[ld++], temp);
            }
            a[la++] = m[temp];
            valid = true;
        }

        while(scanf("%s", temp) == 1 && temp[0] != '#') {
            if(m[temp] == 0) {
                m[temp] = cnt++;
                strcpy(dict[ld++], temp);
            }
            b[lb++] = m[temp];
            valid = true;
        }
        if(valid) {
            la--, lb--;
            calc_dp();
            print_dp();
        }
    }
}
