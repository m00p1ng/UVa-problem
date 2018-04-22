#include <cstdio>

int main() {
    int n;
    int count = 0;
    while(scanf("%d", &n), n) {
        bool found = false;

        count++;
        if(count > 1) puts("");
        
        for(int down = 1234; down <= 98765/n; down++) {
            int up = down*n;
            int temp;
            int used = (down < 10000);
            temp = up;
            while(temp) { used |= 1 << (temp % 10); temp /= 10; }
            temp = down;
            while(temp) { used |= 1 << (temp % 10); temp /= 10; }

            if(used == (1<<10)-1) {
                printf("%05d / %05d = %d\n", up, down, n);
                found = true;
            }
        }
        if(!found) printf("There are no solutions for %d.\n", n);
    }
}

