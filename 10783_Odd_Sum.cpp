#include <cstdio>

int main() {
    int ts;
    scanf("%d", &ts);
     for(int i = 1; i <= ts; i++){
        int a, b, sum = 0;
        scanf("%d %d", &a, &b);
        if(a % 2 == 0) a++;
        if(b % 2 == 0) b--;

        int na = a/2;
        int nb = b/2 + 1; 
        
        sum = nb*nb - na*na;
        printf("Case %d: %d\n", i, sum);
    }
}
