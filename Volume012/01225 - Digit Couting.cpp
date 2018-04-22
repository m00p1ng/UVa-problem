#include <cstdio>
#include <cstring>

int digit[10010][10] = {0};

void copy_prev(int i) {
    for(int j = 0; j < 10; j++) {
        digit[i][j] = digit[i-1][j];
    }
}

void gen_digit() {
    char num[100];
    for(int i = 1; i <= 10000; i++) {
        copy_prev(i);

        sprintf(num, "%d", i);
        for(int j = 0; j < strlen(num); j++) {
            digit[i][num[j] - '0']++;
        }
    }
}

int main() {
    gen_digit();
    int ts, n;
    scanf("%d", &ts);

    while(ts--) {
        scanf("%d", &n);
        printf("%d", digit[n][0]);
        for(int i = 1; i < 10; i++) {
            printf(" %d", digit[n][i]);
        }
        puts("");
    }
}
