#include <cstdio>
#include <cmath>

int main() {
    int ts, a, b, mf, md, tf;
    double temp;
    scanf("%d", &ts);
    
    while(ts--) {
        mf = md = 0;
        scanf("%d %d", &a, &b);
        for(int i = a; i <= b; i++) {
            tf = 0;
            temp = sqrt(i);
            for(int j = 1; j <= temp; j++) {
                if(i % j == 0) {
                    tf++;
                    if(j < temp) tf++;
                }
            }
            if(tf > mf) {
                mf = tf;
                md = i;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", a, b, md, mf);
    }
}
