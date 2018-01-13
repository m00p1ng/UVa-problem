#include <cstdio>
#include <cstring>

const char ENCODE[] = "WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./1234567890-=";
const char DECODE[] = "QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.`1234567890-";
const int ENCODE_LEN = strlen(ENCODE);

char decode_char(char c) {
    for(int j = 0; j < ENCODE_LEN; j++) {
        if(c == ENCODE[j]) {
            return DECODE[j];
        }
    }
    return c;
}

int main() {
    char c;

    while(scanf("%c", &c) == 1) {
        char d = decode_char(c);
        printf("%c", d);
    }
}
