#include <cstdio>

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        int h, m;
        scanf("%d:%d", &h, &m);
        if(h == 12 && m == 0) printf("12:00\n");
        else {
            m = m ? 60-m : 0;
            if(m == 0) h--;
            h = (h >= 11) ? 23-h : 11-h;

            printf("%02d:%02d\n", h, m);
        }
    }
}

