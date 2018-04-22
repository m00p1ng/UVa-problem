#include <cstdio>
#include <cstring>

int score(char c) {
    if(c >= 'a' && c <= 'z') return c - 'a' + 1;
    if(c >= 'A' && c <= 'Z') return c - 'A' + 1;
    return 0;
}

int digit_root(int a) {
    if(a % 9 == 0) return 9;
    return a % 9;
}

int main() {
    char a[100], b[100];

    while(fgets(a, 100, stdin)) {
        fgets(b, 100, stdin);
        double score_a = 0;
        double score_b = 0;
        for(int i = 0; i < strlen(a); i++) {
            score_a += score(a[i]);
        }

        for(int i = 0; i < strlen(b); i++) {
            score_b += score(b[i]);
        }

        double s;
        score_a = digit_root(score_a);
        score_b = digit_root(score_b);

        if(score_a < score_b) s = score_a/score_b*100;
        else s = score_b/score_a*100;

        printf("%.2lf %%\n", s);
    }
}
