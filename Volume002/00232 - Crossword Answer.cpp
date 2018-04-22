#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int r, c;
char board[20][20];

typedef pair<int, string> is;

string across_handle(int i, int j) {
    string temp = "";
    while(j < c && board[i][j] != '*') {
        temp += board[i][j];
        j++;
    }
    return temp;
}

string down_handle(int i, int j) {
    string temp = "";
    while(i < r && board[i][j] != '*') {
        temp += board[i][j];
        i++;
    }
    return temp;
}

int main() {
    int ts = 0;
    while(scanf("%d", &r), r) {
        scanf("%d", &c);

        for(int i = 0; i < r; i++) {
            scanf("%s", board[i]);
        }

        queue<is> across, down;
        int cnt = 1;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(board[i][j] != '*') {
                    bool flag = false;
                    if((j >= 1 && board[i][j-1] == '*') || j == 0) {
                        across.push(is(cnt, across_handle(i, j)));
                        flag = true;
                    }
                    if((i >= 1 && board[i-1][j] == '*') || i == 0) {
                        down.push(is(cnt, down_handle(i, j)));
                        flag = true;
                    }
                    if(flag) cnt++;
                }
            }
        }
        if(ts) puts("");
        printf("puzzle #%d:\n", ++ts);
        puts("Across");
        while(!across.empty()) {
            is v = across.front(); across.pop();
            printf("%3d.%s\n", v.first, v.second.c_str());
        }
        puts("Down");
        while(!down.empty()) {
            is v = down.front(); down.pop();
            printf("%3d.%s\n", v.first, v.second.c_str());
        }
    }
}
