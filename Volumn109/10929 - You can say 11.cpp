#include <cstdio>
#include <cstring>

int main() {
    char n[1010];
    while(scanf("%s", n), strcmp(n, "0")) {
        int len = strlen(n);
        int sum = n[len - 1] - '0';

        bool is_even = true;

        for(int i = len - 2; i >= 0; i--) {
            if(is_even) {
                sum -= n[i] - '0';
            } else {
                sum += n[i] - '0';
            }
            is_even = !is_even;
        }
        if(sum % 11 == 0) printf("%s is a multiple of 11.\n", n);
        else printf("%s is not a multiple of 11.\n", n);
    }
}
