#include <cstdio>

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int ts;
    scanf("%d\n", &ts);
    int arr[200];
    char buff[100000];

    while(ts--) {
        int m = 0;
        int cnt = 0;
        int num = 0;
        bool found_num = false;
        fgets(buff, 100000, stdin);
        
        for(int i = 0; buff[i]; i++) {
            if(buff[i] >= '0' && buff[i] <= '9') {
                num = num*10 + buff[i] - '0';
                found_num = true;
            } else {
                if(found_num) {
                    arr[cnt++] = num;
                }
                num = 0;
                found_num = false;
            }
        }

        for(int i = 0; i < cnt - 1; i++) {
            for(int j = i + 1; j < cnt; j++) {
                int n = gcd(arr[i], arr[j]);
                if(n > m) {
                    m = n;
                }
            }
        }
        printf("%d\n", m);
    }
}
