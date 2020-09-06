#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

bool valid_sq[10100];

void generate_sq() {
    for (int i = 1000; i <= 10000; i++) {
        double val = sqrt(i);
        double next_val = ceil(val);

        valid_sq[i] = val == next_val;
    }
}

int main() {
    generate_sq();

    int ts;
    char v[10], tmp[10];
    scanf("%d", &ts);

    for (int t = 1; t <= ts; t++) {
        scanf("%s", v);
        int cnt = 0;

        for(int k = 0; k < 4; k++) {
            strcpy(tmp, v);
            for (int i = 0; i < 10; i++) {
                tmp[k] = '0' + i; 
                int val = atoi(tmp);

                if (valid_sq[val] && strcmp(tmp, v) != 0) {
                    cnt++;
                }
            }
        }

        printf("Case %d: %d\n", t, cnt);
    }
}
