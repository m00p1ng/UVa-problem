#include <cstdio>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    int cur_sum, max_sum;

    while(scanf("%d", &n), n != 0) {
        cur_sum = 0;
        max_sum = -1e6;

        int temp;
        for(int i = 0; i < n; i++) {
            scanf("%d", &temp);
            
            max_sum = max(max_sum, max(cur_sum+temp, temp));
            if(cur_sum < 0) {
                cur_sum = 0;
            }

            cur_sum += temp;
        } 

        if(max_sum > 0) {
            printf("The maximum winning streak is %d.\n", max_sum);
        } else {
            puts("Losing streak.");
        }
    }
}
