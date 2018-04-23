#include <cstdio>
#include <cctype>

char board[10][10];

int knr[] = {2, 1, 1, 2, -2, -1, -1, -2};
int knc[] = {-1, 2, -2, 1, -1, 2, -2, 1};

int kir[] = {1, 1, 1, 0, -1, -1, -1, 0};
int kic[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int rr[] = {1, 0, -1, 0};
int rc[] = {0, 1, 0, -1};

int br[] = {1, -1, -1, 1};
int bc[] = {1, 1, -1, -1};

int input_board() {
    int b_line, k;
    b_line = 0;
    for(int i = 0; i < 8; i++) {
        k = 0;
        scanf("%s", board[i]);
        for(int j = 0; j < 8; j++) {
            k += (board[i][j] == '.');          
        }
        b_line += (k == 8);
    }
    return b_line;
}

bool knight_move(bool w, int i, int j) {
    int ni, nj;
    for(int d = 0; d < 8; d++) {
        ni = i + knr[d]; 
        nj = j + knc[d];
        if(ni >= 0 && nj >= 0 && ni < 8 && nj < 8) {
            if(!w && board[ni][nj] == 'K')  return true;
            if(w && board[ni][nj] == 'k') return true;
        }
    }
    return false;
}

bool pawn_move(bool w, int i, int j) {
    int ni;
    ni = i;
    if(w) ni--;
    else ni++;
    if(j-1 >= 0 && ((!w && board[ni][j-1] == 'K') || (w && board[ni][j-1] == 'k'))) return true;
    if(j+1 < 8 && ((!w && board[ni][j+1] == 'K') ||  (w && board[ni][j+1] == 'k'))) return true;
    return false;
}

bool rook_move(bool w, int i, int j) {
    int ni, nj;
    bool is_valid[] = {1, 1, 1, 1};

    for(int k = 1; k < 8; k++) {
        for(int d = 0; d < 4; d++) {
            if(!is_valid[d]) continue;
            ni = i + k*rr[d];
            nj = j + k*rc[d];
            if(ni >= 0 && nj >= 0 && ni < 8 && nj < 8) {
                if(!w && board[ni][nj] == 'K') return true;
                if(w && board[ni][nj] == 'k') return true;
                if(board[ni][nj] != '.') is_valid[d] = false;
            } else is_valid[d] = false;
        }
    }
    return false;
}

bool bishop_move(bool w, int i, int j) {
    int ni, nj;
    bool is_valid[] = {1, 1, 1, 1};
    for(int k = 1; k < 8; k++) {
        for(int d = 0; d < 4; d++) {
            if(!is_valid[d]) continue;
            ni = i + k*br[d];
            nj = j + k*bc[d];
            if(ni >= 0 && nj >= 0 && ni < 8 && nj < 8) {
                if(!w && board[ni][nj] == 'K') return true;
                if(w && board[ni][nj] == 'k') return true;
                if(board[ni][nj] != '.') is_valid[d] = false;
            } else is_valid[d] = false;
        }
    }
    return false;
}

int main() {
    bool a, b;
    int ni, nj;
    int ts = 0;

    while(1) {
        if(input_board() == 8) break;
        a = b = false;

        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(board[i][j] == '.' || isupper(board[i][j])) continue;
                if(a) break;

                switch(board[i][j]) {
                    case 'n': a = knight_move(false, i, j); break;
                    case 'p': a = pawn_move(false, i, j); break;
                    case 'r': a = rook_move(false, i, j); break;
                    case 'b': a = bishop_move(false, i, j); break;
                    case 'q': a = bishop_move(false, i, j) || rook_move(false, i, j); break;
                }
            }
        }


        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(board[i][j] == '.' || islower(board[i][j])) continue;
                if(b) break;

                switch(board[i][j]) {
                    case 'N': b = knight_move(true, i, j); break;
                    case 'P': b = pawn_move(true, i, j); break;
                    case 'R': b = rook_move(true, i, j); break;
                    case 'B': b = bishop_move(true, i, j); break;
                    case 'Q': b = bishop_move(true, i, j) || rook_move(true, i, j); break;
                }
            }
        }
        printf("Game #%d: ", ++ts);
        if(b) printf("black");
        else if(a) printf("white");
        else printf("no");
        puts(" king is in check.");
    }
}
