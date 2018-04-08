#include <cstdio>

int main() {
    int ts, s;
    int from[20010];
    from[1] = 1;
    
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        scanf("%d", &s);

        int temp, idx = 1, longest, sum, cnt;
        longest = sum = cnt = 0;

        for(int i = 2; i <= s; i++) {
            scanf("%d", &temp);
            sum += temp;
            if(sum >= 0) {
                from[i] = from[i-1];
                cnt++;
                if(sum > longest || (sum == longest && cnt > idx-from[idx])) {
                    longest = sum;
                    idx = i;
                }
            } else {
                from[i] = i;
                sum = cnt = 0;
            }
        }

        if(idx ==1)
            printf("Route %d has no nice parts\n", t);
        else
            printf("The nicest part of route %d is between stops %d and %d\n", t, from[idx], idx);
    }
}

