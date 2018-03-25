#include <cstdio>

int main() {
    int p[7], sum, cnt;

    while(1) {
        sum = cnt = 0;
        for(int i = 1; i <= 6; i++) {
            scanf("%d", &p[i]);
            sum += p[i];
        }
        if(sum == 0) break;

        cnt += p[6] + p[5] + p[4] + (p[3]+3)/4;

        p[1] -= p[5]*11;
        p[2] -= p[4]*5;
        p[3] %= 4;

        if(p[3] == 1) {
            p[2] -= 5;
            p[1] -= 7;
        } else if(p[3] == 2) {
            p[2] -= 3;
            p[1] -= 6;
        } else if(p[3] == 3) {
            p[2] -= 1;
            p[1] -= 5;
        }
        
        if(p[2] > 0) {
            cnt += (p[2]+8)/9;
            p[2] -= 9*((p[2]+8)/9);
        }

        if(p[2] < 0) {
            p[1] += p[2]*4;
        }

        if(p[1] > 0) {
            cnt += (p[1]+35)/36;
        }
        printf("%d\n", cnt);
    }
}

