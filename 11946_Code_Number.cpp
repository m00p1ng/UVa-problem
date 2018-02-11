#include <cstdio>
#include <cstring>

int main() {
    char s[10000];
    int n;
    char code[] = "OIZEASGTBP";
    scanf("%d\n", &n);

    while(fgets(s, 10000, stdin)) {
        int len = strlen(s);
        for(int i = 0; i < len; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                printf("%c", code[s[i]-'0']);
            } else putchar(s[i]);
        }
    }
}
