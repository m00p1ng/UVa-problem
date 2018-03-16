#include <cstdio>

int main() {
    int ts;
    scanf("%d\n", &ts);
    while(ts--) {
        char c;
        int m, n, result;
        scanf("%c %d %d\n", &c, &m, &n);

        if(c == 'r' || c == 'Q') result = m < n ? m : n;
        else if(c == 'k') result = (m*n+1)/2;
        else result = ((m+1)/2) * ((n+1)/2);

        printf("%d\n", result);
    }
}

