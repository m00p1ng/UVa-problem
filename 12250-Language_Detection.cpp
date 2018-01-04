#include <cstdio>
#include <cstring>

int main() {
    char temp[20];
    int cnt = 0;

    while(scanf("%s", temp), temp[0] != '#') {
        printf("Case %d: ", ++cnt);

        if(!strcmp("HELLO", temp)) {
            puts("ENGLISH");
        } else if(!strcmp("HOLA", temp)){
            puts("SPANISH");
        } else if(!strcmp("HALLO", temp)) {
            puts("GERMAN");
        } else if(!strcmp("BONJOUR", temp)) {
            puts("FRENCH");
        } else if(!strcmp("CIAO", temp)) {
            puts("ITALIAN");
        } else if(!strcmp("ZDRAVSTVUJTE", temp)) {
            puts("RUSSIAN");
        } else {
            puts("UNKNOWN");
        }

    }
}
