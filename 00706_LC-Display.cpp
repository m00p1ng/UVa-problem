#include <cstdio>
#include <cstring>

char display[][31] = {
    " -     -  -     -  -  -  -  - ",
    "| |  |  |  || ||  |    || || |",
    "       -  -  -  -  -     -  - ",
    "| |  ||    |  |  || |  || |  |",
    " -     -  -     -  -     -  - "
};

void print_row(char *s, int i, int n) {
    int len = strlen(s);
    for(int j = 0; j < len; j++) {
        int idx = 3*(s[j] - '0');

        putchar(display[i][idx]);
        for(int k = 0; k < n; k++) {
            putchar(display[i][idx+1]);
        }
        putchar(display[i][idx+2]);

        if(j+1 != len) putchar(' ');
    }
    puts("");
}

int main () {
    int n;
    char s[10];
    while(scanf("%d %s", &n, s), n) {
        print_row(s, 0, n);

        for(int i = 0; i < n; i++) print_row(s, 1, n); 

        print_row(s, 2, n);

        for(int i = 0; i < n; i++) print_row(s, 3, n); 

        print_row(s, 4, n);


        puts("");
    }
}


