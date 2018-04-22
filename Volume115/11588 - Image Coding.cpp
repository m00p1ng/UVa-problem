#include <cstdio>

int main() {
    int ts;
    int r, c, m, n;
    char img[40];
    int max, cnt;

    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        int freq[100] = {0};
        max = cnt = 0;
        scanf("%d %d %d %d", &r, &c, &m, &n);
        for(int i = 0; i < r; i++) {
            scanf("%s", img);
            for(int j = 0; j < c; j++) {
                int idx = img[j] - 'A';
                freq[idx]++;
                if(freq[idx] > max) max = freq[idx];
            }
        }

        for(int i = 0; i < 26; i++) {
            if(freq[i] == max) cnt++; 
        }

        int total = cnt*max*m + (r*c-max*cnt)*n;
        printf("Case %d: %d\n", t, total);
    }
}
