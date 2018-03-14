#include <cstdio>

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        int s;
        scanf("%d", &s);
        if(s < 10) {
            printf("%d\n", s);
            continue;
        }
        int temp = s;
        int freq[10] = {0};

        for(int i = 9; i >= 2; i--) {
            while(temp % i == 0) {
                freq[i]++;
                temp /= i;
            }
        }

        if(temp != 1) puts("-1");
        else {
            for(int i = 2; i <= 9; i++) {
                if(freq[i] == 0) continue;
                for(int j = 0; j < freq[i]; j++) {
                    printf("%d", i);
                }
            }
            puts("");
        }
    }
}

