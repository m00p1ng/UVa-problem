#include <cstdio>
#include <stack>
using namespace std;

int main() {
    int n;

    while(scanf("%d", &n), n) {
        int l[1000];

        while(true) {
            scanf("%d", &l[0]);
            if(l[0] == 0) {
                break;
            }

            for(int i = 1; i < n; i++) {
                scanf("%d", &l[i]);
            }

            stack<int> s;
            int cur = n;
            int i = n-1;

            while(i >= 0 && cur > 0) {
                if(l[i] == cur) {
                    cur--;
                } else {
                    s.push(l[i]);
                }

                i--;

                while(!s.empty() && s.top() == cur) {
                    cur--;
                    s.pop();
                } 
            }

            if(s.empty()) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
        puts("");
    }
}
