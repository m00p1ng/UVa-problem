#include <cstdio>
#include <cmath>

int perfect(int number) {
    int ans = 1;
    for(int i = 2; i <= sqrt(number); i++) {
        if(number % i == 0) {
            ans += i;
            if(number/i != i) {
                ans += number/i;
            }
        }
    }
    return ans;
}

int main() {
    int number;
    puts("PERFECTION OUTPUT");

    while(scanf("%d", &number), number) {
        int ans = perfect(number); 
        int diff = ans - number;

        if(number == 1 || diff < 0) {
            printf("%5d  DEFICIENT\n", number);
        } else if(diff == 0) {
            printf("%5d  PERFECT\n", number);
        } else {
            printf("%5d  ABUNDANT\n", number);
        }
    }

    puts("END OF OUTPUT");
}

