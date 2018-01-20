#include <cstdio>

int main() {
    char song[][1000] = {
        "Happy", "birthday", "to", "you",
        "Happy", "birthday", "to", "you",
        "Happy", "birthday", "to", "Rujia",
        "Happy", "birthday", "to", "you",
    };

    int n;
    char name[100][200];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", name[i]);
    }
    
    int r = 16*(n/16 + (n % 16 != 0));

    for(int i = 0; i < r; i++) {
        printf("%s: %s\n", name[i%n], song[i%16]);
    }
}
