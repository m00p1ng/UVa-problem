#include <cstdio>
#include <cstring>
#include <cctype>

double w_mole(char c) {
    switch(c) {
        case 'C': return 12.01; break;
        case 'H': return 1.008; break;
        case 'O': return 16.00; break;
        case 'N': return 14.01; break;
    }
    return 0;
}

int main() {
    int ts, n, len;
    char sym[100];
    double w;
    scanf("%d", &ts);

    while(ts--) {
        scanf("%s", sym);
        w = 0;
        n = 0;
        len = strlen(sym);
        for(int i = 0; i < len; i++) {
            if(isdigit(sym[i])) continue;

            if(i+1 == len || !isdigit(sym[i+1])) {
                w += w_mole(sym[i]);
            } else {
                if(i+3 <= len) {
                    n = sym[i+1] - '0';
                    if(isdigit(sym[i+2])) n = n*10 + (sym[i+2]-'0');
                } else if(i+2 == len) n = sym[i+1] - '0';
                w += w_mole(sym[i])*n;
            }
        }
        printf("%.3lf\n", w);
    }
}

