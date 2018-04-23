#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct state {
    int i, j;
    int depth;
    int vowel;
    int cost;
    int visited;
    int board;
};

map<int, bool> visited;
vector<int> vi;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1 ,-1};

bool is_valid(int i, int j) {
    return i >= 0 && j >= 0 && i < 4 && j < 4;
}

bool isvowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}

void print_string(int n) {
    char a, b, c, d;
    a = b = c = d = 'A';
    d += n % 26; n /= 26;
    c += n % 26; n /= 26;
    b += n % 26; n /= 26;
    a += n % 26;

    printf("%c%c%c%c\n", a, b, c, d);
}

void dfs(char board[][10], bool isone, state s) {
    if(!is_valid(s.i, s.j) || s.vowel == 3) return;

    if(s.depth == 4) {
        if(s.vowel == 2) {
            if(isone) {
                visited[s.cost] = true;
            } else if(visited[s.cost]) {
                vi.push_back(s.cost);
                visited[s.cost] = false;
            }
        }
        return;
    }
    int nc = board[s.i][s.j] - 'A';

    if((s.board>>(4*s.i+s.j))&1) return;
    if(!isvowel(board[s.i][s.j])) s.visited |= 1<<nc;

    s.cost = s.cost*26 + nc;
    s.vowel += isvowel(board[s.i][s.j]);
    s.board |= 1<<(4*s.i+s.j);

    for(int d = 0; d < 8; d++) {
        dfs(board, isone, {s.i+dr[d], s.j+dc[d], s.depth+1, s.vowel, s.cost, s.visited, s.board});
    }
}

bool handle_input(char ba[][10], char bb[][10]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) scanf(" %c", &ba[i][j]);
        for(int j = 0; j < 4; j++) scanf(" %c", &bb[i][j]);
    }
    return ba[0][0] != '#';
}

int main() {
    bool ts = false;
    char ba[10][10], bb[10][10];
    while(handle_input(ba, bb)) {
        visited.clear();
        vi.clear();
        if(ts) puts(""); ts = true;

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                dfs(ba, true, {i, j, 0, 0, 0, 0, 0});
            }
        }
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                dfs(bb, false, {i, j, 0, 0, 0, 0, 0});
            }
        }

        if(vi.size() != 0) {
            sort(vi.begin(), vi.end());
            for(int i = 0; i < vi.size(); i++) {
                print_string(vi[i]);
            }
        } else {
            puts("There are no common words for this pair of boggle boards.");
        }
    }
}
