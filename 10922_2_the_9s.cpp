#include <cstdio>
#include <cstring>

int digit_sum_char(char * number) {
    int len = strlen(number);
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += number[i] - '0';
    }
    return sum;
}

int count_9(int number) {
    if(number < 10) return 1;
    
    int sum = 0;
    while(number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return 1 + count_9(sum);
}

int main() {
    char number[1001];
    while(scanf("%s", number), strcmp(number, "0")) {
        int sum = digit_sum_char(number);
        if(sum % 9 != 0) {
            printf("%s is not a multiple of 9.\n", number);
        } else {
            printf("%s is a multiple of 9 and has 9-degree %d.\n", number, count_9(sum));
        }
    }
}

