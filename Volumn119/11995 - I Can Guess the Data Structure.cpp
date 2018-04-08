#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n, num;
    bool is_s, is_q, is_pq;
    int cmd, item, sz;

    while(scanf("%d", &n) == 1) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        is_s = is_q = is_pq = true;
        sz = 0;
        while(n--) {
            scanf("%d %d", &cmd, &item); 
            if(cmd == 1) {
                s.push(item);
                q.push(item);
                pq.push(item);
                sz++;
            } else {
                if(sz <= 0) is_s = is_q = is_pq = false; 
                if(is_s) {
                    if(s.top() != item) is_s = false;
                    s.pop();
                }
                if(is_q) {
                    if(q.front() != item) is_q = false;
                    q.pop();
                }
                if(is_pq) {
                    if(pq.top() != item) is_pq = false;
                    pq.pop();
                }
                sz--;
            }
        }
        int guess = is_s + is_q + is_pq;
        if(guess == 0) puts("impossible");
        else if(guess == 2 || guess == 3) puts("not sure");
        else if(is_s) puts("stack");
        else if(is_q) puts("queue");
        else if(is_pq) puts("priority queue");
    }
}
