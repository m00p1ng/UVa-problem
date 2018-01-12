#include <cstdio>
#include <cstring>

bool is_palin(long long n) {
    char temp[100];

    snprintf(temp, 100, "%lld", n);

    int len = strlen(temp);
    for(int i = 0; i < len/2; i++) {
        if(temp[i] != temp[len-1-i])  {
            return false;
        }
    }

    return true;
}

long long rev_num(long long n) {
    long long rev = 0;

    while(n >= 1) {
        rev = rev*10 + n%10;
        n /= 10;
    }
    return rev;
}

int main() {
    int ts;
    scanf("%d", &ts);

    while(ts--) {
        long long n;
        int rnd = 0;
        scanf("%lld", &n);
        n += rev_num(n); 
        rnd++;

        for(int i = 0; i < 1000 && !is_palin(n); i++) {
            n += rev_num(n); 
            rnd++;
        }

        printf("%d %lld\n", rnd, n); 
    }
}
