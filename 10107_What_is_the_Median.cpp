#include <cstdio>
#include <cstring>

int main() {
    int n, cnt = 0, data[10000];

    while(scanf("%d", &n) == 1) {
        int i = 0;

        while(i < cnt && n > data[i]) i++;
        if(i == cnt) data[i] = n;
        else {
            memcpy(data+i+1, data+i, sizeof(int)*(cnt-i));
            data[i] = n;
        }
        if(cnt & 1) printf("%d\n", (data[cnt/2]+data[cnt/2+1])/2);
        else printf("%d\n", data[cnt/2]);
        cnt++;
    }
}
