#include <cstdio>
#include <cstring>

int main() {
    bool work[1000001];

    int n, m;
    int max, min;

    while(scanf("%d %d", &n, &m), n || m) {
        memset(work, false, sizeof work);
        bool is_confilct = false;

        int s, e, r;

        for(int i = 0; i < n; i++) {
            scanf("%d %d", &s, &e);
            if(!is_confilct) {
                for(int j = s; j < e; j++) {
                    if(work[j]) {
                        is_confilct = true;
                        break;
                    }
                    work[j] = true;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &s, &e, &r);
            if(!is_confilct) {
                for(int j = 0; r*j+s <= 1000000; j++) {
                    int offset = r*j;
                    for(int k=offset+s; k < offset+e && k <= 1000000; k++) {
                        if(work[k]) {
                            is_confilct = true;
                            break;
                        }
                        work[k] = true;
                    }
                }
            }
        }

        puts(is_confilct ? "CONFLICT" : "NO CONFLICT");
    }
}

