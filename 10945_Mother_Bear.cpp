#include <cstdio>
#include <cstring>
#include <cctype>

bool is_palin(char* s) {
    int len = strlen(s)-2;
    int i = 0;
    int j = len;

    while(i <= j) {
        if(tolower(s[i]) == tolower(s[j])) {
            i++;
            j--;
        } else {
            if(!isalpha(s[i])) i++; 
            else if(!isalpha(s[j])) j--; 
            else return false; 
        }
    }
    return true;
}

int main() {
    char s[10000];
    while(fgets(s, 10000, stdin), strcmp(s, "DONE\n")) {
        if(is_palin(s)) puts("You won't be eaten!");
        else puts("Uh oh..");
    }
}
