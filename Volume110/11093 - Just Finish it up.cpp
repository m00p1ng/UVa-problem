#include <cstdio>

int main() {
    int ts, n, temp, diff[100001];
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        scanf("%d", &n);

        for(int i = 0; i < n; i++) {
            scanf("%d", &diff[i]);
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &temp);
            diff[i] -= temp;
        }
        printf("Case %d: ", t);

        int i = 0, k;
        int sum = -1;
        while(i < n && sum < 0) {
            sum = 0;
            for(int j = 0; j < n; j++) {
                sum += diff[(i+j) % n];
                if(sum < 0) {
                    i += j;
                    break;
                }
            }
            i++;
        }

        if(sum >= 0) printf("Possible from station %d\n", i);
        else puts("Not possible");
    }
}
