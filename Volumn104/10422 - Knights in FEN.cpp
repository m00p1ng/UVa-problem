#include <cstdio>
#include <set>
#include <queue>
#include <string>
using namespace std;

typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef pair<si, ii> state;

const char end_state[] = "111110111100 110000100000";
string init;
int r, c;

int dr[] = {-2,-1,1,2,2,1,-1,-2};
int dc[] = {1,2,2,1,-1,-2,-2,-1};

void handle_input() {
    char temp[100];
    init = "";
    for(int i = 0; i < 5; i++) {
        fgets(temp, 100, stdin);
        temp[5] = '\0';
        init += temp;
        for(int j = 0; j < 5; j++) {
            if(temp[j] == ' ') {
                r = i;
                c = j;
            }
        }
    }
}

bool is_finished(string s) {
    return s == end_state;
}

int bfs() {
    queue<state> q;
    set<string> s;

    q.push(state(si(init, 0), ii(r,c)));

    while(!q.empty()) {
        state v = q.front(); q.pop();
        si board = v.first;
        ii hole = v.second;

        if(board.second == 11) break;
        if(is_finished(board.first)) return board.second;
        if(s.find(board.first) != s.end()) continue; 

        s.insert(board.first);

        for(int d = 0; d < 8; d++) {
            int nr = hole.first + dr[d];
            int nc = hole.second + dc[d];

            if(nr >= 0 && nr < 5 && nc >= 0 && nc < 5) {
                string temp = board.first;
                temp[5*hole.first+hole.second] = temp[5*nr+nc];
                temp[5*nr+nc] = ' ';
                q.push(state(si(temp, board.second+1), ii(nr, nc)));
            }
        }

    }
    return 11;
}

int main() {
    int ts;
    scanf("%d\n", &ts);

    while(ts--) {
        handle_input();
        int mv = bfs();
        if(mv < 11) printf("Solvable in %d move(s).\n", mv);
        else puts("Unsolvable in less than 11 move(s).");
    }
}
