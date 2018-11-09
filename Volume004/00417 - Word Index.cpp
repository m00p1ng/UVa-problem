#include <cstdio>
#include <map>
#include <string>
#include <cstring>
using namespace std;

map<string, int> m;
int cnt = 1;
char s[10];

void gen_word(int d, int c, int idx) {
    if(c == d) {
        m[s] = cnt++;
        return;
    }

    for(char i = idx+'a'; i < 26+'a'; i++) {
        s[c] = i;
        gen_word(d, c+1, i-'a'+1); 
    }
}

void gen_word_list() {
    for(int i = 1; i <= 5; i++) {
        gen_word(i, 0, 0);
    }
}

int main() {
    gen_word_list();
    char word[1000];
    while(scanf("%s", word) == 1) {
        printf("%d\n", m[word]);
    }
}
