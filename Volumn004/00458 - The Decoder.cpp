#include <cstdio>
#include <cstring>

int main() {
    char temp[100000];
    while(fgets(temp, 100000, stdin)) {
        int len = strlen(temp)-1;
        for(int i = 0; i < len; i++) {
            printf("%c", temp[i]-7);
        }
        puts("");
    }
}
