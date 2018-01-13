#include <cstdio>
#include <cstring>

int main() {
    int ts;
    scanf("%d", &ts);
    int storage[100];
    char cmd[100010];

    for(int t = 1; t <= ts; t++) {
        memset(storage, 0, sizeof(storage));
        scanf("%s", cmd);

        int len = strlen(cmd);

        int ptr = 0;
        for(int i = 0; i < len; i++) {
            switch(cmd[i]) {
                case '<': 
                    ptr--;
                    if(ptr == -1) ptr = 99;
                    break;
                case '>':
                    ptr++;
                    if(ptr == 100) ptr = 0;
                    break;
                case '+': storage[ptr]++; break;
                case '-': storage[ptr] += 255; break;
            }
        }

        printf("Case %d:", t);
        for(int i = 0; i < 100; i++) {
            printf(" %02X", storage[i] % 256);
        }
        puts("");
    }
}
