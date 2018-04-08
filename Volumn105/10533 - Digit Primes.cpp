#include <cstdio>
#include <cstring>
#define MIL 1000000

bool prime[MIL] = {0};
bool dp[MIL];
int total[MIL] = {0};

int sum_digit(int n) {
    char temp[100];
    int sum = 0;
    sprintf(temp, "%d", n);

    for(int i = 0; i < strlen(temp); i++) {
        sum += temp[i] - '0';
    }
    return sum;
}

void gen_digit() {
    prime[0] = prime[1] = 1;
    for(int i = 4; i < MIL; i+=2) prime[i] = 1;

    for(int i = 3; i < MIL; i+=2) {
        for(int j = 2; i*j < MIL; j++) {
            prime[i*j] = 1;
        }
    }

    for(int i = 1; i < MIL; i++) {
        dp[i] = !prime[i] && !prime[sum_digit(i)];
        total[i] = total[i-1] + dp[i];
    }
}

int main() {
    gen_digit();
    int ts;
    int a, b, cnt;
    scanf("%d", &ts);
    for(int i = 0; i < ts; i++) {
        scanf("%d %d", &a, &b);
        cnt = total[b] - total[a] + dp[a];
        printf("%d\n", cnt);
    }
}
