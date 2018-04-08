#include <cstdio>
#include <cstring>

int p[10001];

int find_set(int a) {
    if(p[a] == a) return a;
    return find_set(p[a]);
}

void union_set(int a, int b) {
    int fa = find_set(a);
    int fb = find_set(b);
    if(fa == fb) return;
    p[fb] = fa;
}

int main() {
    int ts, a, b, n, success, unsuccess;
    char cmd, buff[1000];
    scanf("%d", &ts);

    while(ts--) {
        scanf("%d\n", &n);
        for(int i = 1; i <= n; i++) p[i] = i;
        unsuccess = success = 0;

        while(fgets(buff, 1000, stdin) && strcmp(buff, "\n")) {
            sscanf(buff, "%c %d %d", &cmd, &a, &b);
            if(cmd == 'c') union_set(a, b);
            else {
                if(find_set(a) == find_set(b)) success++;
                else unsuccess++; 
            }
        }
        printf("%d,%d\n", success, unsuccess);
        if(ts) puts("");
    }
}

