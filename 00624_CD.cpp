#include <cstdio>

int n, t;
int track[100];
int sum, max_pos;

void cd(int start, int cost, int pos) {
    int new_pos = (pos | (1 << start));
    int new_cost = cost + track[start];

    if(new_cost > sum && new_cost <= n) {
        sum = new_cost;
        max_pos = new_pos;
    }
    if(new_cost == n || start >= t-1) {
        return;
    }

    if(new_cost < n) {
        cd(start+1, new_cost, new_pos);
    }
    cd(start+1, cost, pos);
}

int main() {
    while(scanf("%d %d", &n, &t) == 2) {
        for(int i = 0; i < t; i++) {
            scanf("%d", &track[i]);
        }
        sum = max_pos = 0;
        cd(0, 0, 0);

        for(int i = 0; i < t; i++) {
            if(max_pos & (1<<i)) {
                printf("%d ", track[i]);
            }
        }
        printf("sum:%d\n", sum);
    }
}
