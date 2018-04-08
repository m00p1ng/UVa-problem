#include <cstdio>
#include <cstring>

int main() {
    char temp[1000];
    while(fgets(temp, 1000, stdin)) {
        printf("%s", temp);
    }
}
