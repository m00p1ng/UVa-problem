#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

typedef pair<int, int> ii;
bool visited[10][10];

void init_board(){
    memset(visited, 0, sizeof(visited));
    visited[2][2] = 1;
}

bool is_bingo() {
    int a, b;

    a = b = 0;
    for(int i = 0; i < 5; i++) {
        a += visited[i][i];
        b += visited[i][4-i];
    }
    if(a == 5 || b == 5) return true;

    for(int i = 0; i < 5; i++) {
        a = b = 0;
        for(int j = 0; j < 5; j++) {
            a += visited[i][j];
            b += visited[j][i];
        }
        if(a == 5 || b == 5) return true;
    }

    return false;
}

int main() {
    int ts;
    scanf("%d", &ts);
    map<int, ii> m;

    while(ts--) {
        m.clear();
        init_board();

        int temp, rnd = 0;
        bool finish = false;
        for(int i = 0; i < 25; i++){
            if(i == 12) continue;
            scanf("%d", &temp);
            m[temp] = ii(i/5 + 1, i%5 + 1);
        }
        
        for(int i = 0; i < 75; i++) {
            scanf("%d", &temp);
            if(finish) continue;
            rnd++;
            if(!m[temp].first && !m[temp].second) continue; 

            visited[m[temp].first-1][m[temp].second-1] = true;
            finish = is_bingo();
        }
        printf("BINGO after %d numbers announced\n", rnd);
    }
}
