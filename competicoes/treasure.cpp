#include <iostream>
using namespace std;

int main() {
    int r, c, moves = 0, x = 0, y = 0;

    cin >> r >> c;

    char board[r][c];
    bool visited[r][c] = {};

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }

    while(true) {
        if(x < 0 || x >= r || y < 0 || y >= c) {
            cout << "Out" << endl;
            return 0;
        }

        if(visited[x][y]) {
            cout << "Lost" << endl;
            return 0;
        }

        visited[x][y] = true;
        moves++;

        if(board[x][y] == 'T') {
            cout << moves-1 << endl;
            return 0;
        }

        switch(board[x][y]) {
            case 'N': x--; break;
            case 'S': x++; break;
            case 'E': y++; break;
            case 'W': y--; break;
        }
    }

    return 0;
}
