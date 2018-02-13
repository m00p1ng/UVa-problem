#include <cstdio>
#include <map>
#include <string>
#include <cstring>
using namespace std;

map<string, char> morse;
void create_morse() {
    morse[".-"] = 'A';
    morse["-..."] = 'B';
    morse["-.-."] = 'C';
    morse["-.."] = 'D';
    morse["."] = 'E';
    morse["..-."] = 'F';
    morse["--."] = 'G';
    morse["...."] = 'H';
    morse[".."] = 'I';
    morse[".---"] = 'J';
    morse["-.-"] = 'K';
    morse[".-.."] = 'L';
    morse["--"] = 'M';
    morse["-."] = 'N';
    morse["---"] = 'O';
    morse[".--."] = 'P';
    morse["--.-"] = 'Q';
    morse[".-."] = 'R';
    morse["..."] = 'S';
    morse["-"] = 'T';
    morse["..-"] = 'U';
    morse["...-"] = 'V';
    morse[".--"] = 'W';
    morse["-..-"] = 'X';
    morse["-.--"] = 'Y';
    morse["--.."] = 'Z';

    morse["-----"] = '0';
    morse[".----"] = '1';
    morse["..---"] = '2';
    morse["...--"] = '3';
    morse["....-"] = '4';
    morse["....."] = '5';
    morse["-...."] = '6';
    morse["--..."] = '7';
    morse["---.."] = '8';
    morse["----."] = '9';

    morse[".-.-.-"] = '.';
    morse["--..--"] = ',';
    morse["..--.."] = '?';
    morse[".----."] = '\'';
    morse["-.-.--"] = '!';
    morse["-..-."] = '/';
    morse["-.--."] = '(';
    morse["-.--.-"] = ')';
    morse[".-..."] = '&';
    morse["---..."] = ':';
    morse["-.-.-."] = ';';
    morse["-...-"] = '=';
    morse[".-.-."] = '+';
    morse["-....-"] = '-';
    morse["..--.-"] = '_';
    morse[".-..-."] = '"';
    morse[".--.-."] = '@';
}

int main() {
    create_morse();
    int ts, idx, midx;
    char s[10000], m[10];
    scanf("%d\n", &ts);

    for(int t = 1; t <= ts; t++) {
        fgets(s, 10000, stdin);
        idx = 0;
        int len = strlen(s)-1;

        if(t > 1) puts("");
        printf("Message #%d\n", t);
        while(idx < len) {
            midx = 0;
            while(s[idx] != ' ' && idx < len) {
                m[midx] = s[idx];
                midx++;
                idx++;
            }
            m[midx] = '\0';
            putchar(morse[m]);
            if(s[++idx] == ' ') {
                putchar(' ');
                ++idx;
            }
        }
        puts("");
    }
}
