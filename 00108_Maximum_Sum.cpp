#include <cstdio>
#include <cstring>

int num[100][100];

int max(int a, int b) {
    return a > b ? a : b;
}

int calc_dp(int n) {
    int max_sum = -1e8;
    int cur_sum;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int a = i; a < n; a++) {
                for(int b = j; b < n; b++){
                    cur_sum = num[a][b];
                    if(i > 0) cur_sum -= num[i-1][b];
                    if(j > 0) cur_sum -= num[a][j-1];
                    if(i > 0 && j > 0) cur_sum += num[i-1][j-1];
                    max_sum = max(max_sum, cur_sum);
                }
            }
        }
    }
    return max_sum;
}

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &num[i][j]);
                if(i > 0) num[i][j] += num[i-1][j];
                if(j > 0) num[i][j] += num[i][j-1];
                if(i > 0 && j > 0) num[i][j] -= num[i-1][j-1];
            }
        }
        printf("%d\n", calc_dp(n));
    }
}
