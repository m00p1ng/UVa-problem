#include <cstdio>
#include <queue>
#include <string>
#include <map>
#define INIT 987654321
using namespace std;

typedef pair<int, string> is;

struct state {
    int depth;
    int board;
    string path;
};

map<int, is> state_space;
map<int, int> visited;
int d[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

int swap_num(int board, int a, int b) {
    int na = (board / d[a]) % 10;
    int nb = (board / d[b]) % 10;
    return board - na*d[a] - nb*d[b] + nb*d[a] + na*d[b];
}

int move_horizontal(int board, int n) {
    int result = swap_num(board, 3*n, 3*n+1);
    return swap_num(result, 3*n+1, 3*n+2);
}

int move_vertical(int board, int n) {
    int result = swap_num(board, n, 3+n);
    return swap_num(result, n, 6+n);
}

void bfs() {
    queue<state> q;
    q.push({0, INIT, ""});
    state_space[INIT] = is(0, "");
    visited[INIT] = true;

    int new_board, new_depth;
    while(!q.empty()) {
        state s = q.front(); q.pop();

        new_depth = s.depth+1;
        for(int i = 0; i < 3; i++) {
            new_board = move_horizontal(s.board, i); 
            if(!visited[new_board]) {
                string new_path = (string)"H" + (char)('1'+i) + s.path;
                q.push({new_depth, new_board, new_path});
                visited[new_board] = true;
                state_space[new_board] = is(new_depth, new_path); 
            }

            new_board = move_vertical(s.board, i); 
            if(!visited[new_board]) {
                string new_path = (string)"V" + (char)('1'+i) + s.path;
                q.push({new_depth, new_board, new_path});
                visited[new_board] = true;
                state_space[new_board] = is(new_depth, new_path); 
            }
        }
    }
}

int main() {
    int n;
    bfs();
    while(scanf("%d", &n), n) {
        int init_state = n;
        for(int i = 1; i < 9; i++) {
            scanf("%d", &n);
            init_state += n*d[i];
        }
        is res = state_space[init_state];
        if(visited[init_state]) printf("%d %s\n", res.first, res.second.c_str());
        else puts("Not solvable");
    }
}
