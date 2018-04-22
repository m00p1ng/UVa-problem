#include <cstdio>
#include <cmath>

int main() {
    int ts;
    scanf("%d", &ts);

    int n, m, j;
    for(int t = 1; t <= ts; t++) {
        m = j = 0;
        scanf("%d", &n);

        int temp;
        for(int i = 0; i < n; i++) {
            scanf("%d", &temp);

            m += ceil((double)(temp+1)/30.0)*10;
            j += ceil((double)(temp+1)/60.0)*15;
        }
        
        printf("Case %d: ", t);
        if(m == j) printf("Mile Juice %d\n", m);
        else if(m < j) printf("Mile %d\n", m);
        else printf("Juice %d\n", j);
    }
}
