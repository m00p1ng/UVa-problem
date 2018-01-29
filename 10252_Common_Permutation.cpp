#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    char a[1010], b[1010];
    while(fgets(a, 1010, stdin)) {
        fgets(b, 1010, stdin);
        int lena = strlen(a)-1;
        int lenb = strlen(b)-1;
        sort(a, a+lena);
        sort(b, b+lenb);

        int min_idx = 0;
        for(int i = 0; i < lena; i++) {
            for(int j = min_idx; j < lenb; j++) {
                if(a[i] == b[j]) {
                    putchar(a[i]);
                    min_idx = j+1;
                    break;
                }
            }
        }
        puts("");
    }
}
