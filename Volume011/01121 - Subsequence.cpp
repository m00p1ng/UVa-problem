#include <cstdio>
#include <queue>
#define INF 1e9
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, s;
    while(scanf("%d %d", &n, &s) == 2) {
        deque<int> dq;
        int m = INF;
        int cur_sum = 0;
        int temp;

        for(int i = 0; i < n; i++) {
            scanf("%d", &temp);
            cur_sum += temp;
            dq.push_back(temp);

            if(cur_sum >= s) {
                while(cur_sum >= s) {
                    int ft = dq.front(); dq.pop_front();
                    cur_sum -= ft;
                }
                m = min(m, dq.size() + 1);
            } 
        }
        if(m == INF) puts("0");
        else printf("%d\n", m);
    }
}
