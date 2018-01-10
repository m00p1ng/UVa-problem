#include <cstdio>
#include <cstring>

bool prime[2000] = { false };

int alpha_score(char c) {
    if(c >= 'a' && c <= 'z') return c - 'a' + 1;
    if(c >= 'A' && c <= 'Z') return c - 'A' + 27;
    return 0;
}

void gen_prime() {
    prime[0] = true;
    for(int i = 2; i <= 1100; i++) {
        for(int j = 2; i*j <= 1100; j++) {
            prime[i*j] = true;
        }
    }
}

int main() {
    char temp[100];
    gen_prime();

    while(scanf("%s", temp) == 1) {
        int score = 0;
        for(int i = 0; i < strlen(temp); i++) {
            score += alpha_score(temp[i]); 
        }
        if(!prime[score]) {
            puts("It is a prime word.");
        } else {
            puts("It is not a prime word.");
        }
    }
}
