#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int n, temp, cost, sum;
    priority_queue<int, vector<int>, greater<int>> pq;

    while(scanf("%d", &n), n) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &temp);
            pq.push(temp);
        }
        
        int sum;
        cost = 0;
        while(!pq.empty()) {
            sum = pq.top(); pq.pop();

            if(!pq.empty()) {
                sum += pq.top(); pq.pop();
            } else {
                break;
            }
            pq.push(sum);
            cost += sum;
        }
        printf("%d\n", cost);
    }
}
