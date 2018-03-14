#include <cstdio>

int main() {
    bool board[10] = { false };

    int number;
    char cmd[20];
    char ig[10];
    bool result = true;

    while(scanf("%d", &number)) {
        if(number == 0) break;
        
        scanf("%s %s", ig, cmd);

        switch(cmd[0]) {
            case 'l':
                for(int i = number - 1; i >= 0; i--) {
                    if(board[i]) {
                        result = false;
                        break;
                    }
                    board[i] = true;
                }
                break;
            case 'h':
                for(int i = number - 1; i < 10; i++) {
                    if(board[i]) {
                        result = false;
                        break;
                    }
                    board[i] = true;
                }
                break;
            case 'o':
                if(!board[number-1]) puts("Stan may be honest");
                else puts("Stan is dishonest");

                for(int i = 0; i < 10; i++) { board[i] = false; }
                result = true;
                break;
        }
    }
}

