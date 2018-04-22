#include <cstdio>
#include <cstring>

int main() {
    char a[1000000], b[1000000];
    while(scanf("%s %s", a, b) == 2) {
        int lena = strlen(a);
        int lenb = strlen(b);

        int j = 0;
        for(int i = 0; i < lenb && j < lena; i++) {
            if(a[j] == b[i]) j++;
        }

        if(j == lena) puts("Yes");
        else puts("No");
    }
}
