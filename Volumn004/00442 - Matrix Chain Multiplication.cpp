#include <cstdio>
#include <cstring>
#include <cctype>
#include <stack>
#include <map>
using namespace std;

typedef pair<int, int> ii;
ii lparen = ii(-1, -1);

bool can_mul(ii a, ii b) {
    return a.second == b.first;
}

int mul_mat(ii a, ii b) {
    return a.first*a.second*b.second;
}

int main() {
    int n, x, y;
    scanf("%d\n", &n);
    map<char, ii> mat;
    char name, e[10000];

    for(int i = 0; i < n; i++) {
        scanf(" %c %d %d", &name, &x, &y);
        mat[name] = ii(x, y);
    }

    while(scanf("%s", e) == 1) {
        int cnt = 0;
        bool is_valid = true;
        ii a, b;
        stack<ii> op;

        for(int i = 0; i < strlen(e) && is_valid; i++) {
            if(e[i] == '(') {
                op.push(lparen);
                continue;
            } else if(e[i] == ')') {
                b = op.top(); op.pop(); op.pop();
            } else {
                b = mat[e[i]];    
            }

            if(!op.empty() && op.top() != lparen) {
                a = op.top(); op.pop();
                if(!can_mul(a, b)) {
                    is_valid = false;
                }
                cnt += mul_mat(a, b);
                b = ii(a.first, b.second);
            }
            op.push(b);
        }
        if(is_valid) printf("%d\n", cnt);
        else puts("error");
    }
}
