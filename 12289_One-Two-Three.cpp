#include <cstdio>
#include <cstring>

int main() {
    int ts;
    scanf("%d", &ts);

    char temp[100];
    while(ts--) {
        scanf("%s", temp); 

        if(strlen(temp) == 5) {
            puts("3");
        } else {
            int one = (temp[0] == 'o') + (temp[1] == 'n') + (temp[2] == 'e');
            int two = (temp[0] == 't') + (temp[1] == 'w') + (temp[2] == 'o');

            if(one > two) {
                puts("1");
            } else {
                puts("2");
            }
        }
    }
}
