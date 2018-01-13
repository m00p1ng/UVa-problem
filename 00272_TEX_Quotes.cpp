#include <cstdio>

int main() {
    char c;
    bool is_first = true;
    while(scanf("%c", &c) == 1) {
        if(c == '"') {
            if(is_first) printf("``");
            else printf("''");
            is_first = !is_first;
        } else {
            printf("%c", c);
        }
    }
}
