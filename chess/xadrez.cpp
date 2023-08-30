/* Nome: Barbara Silveira Rodrigues
   Materia: Desafios de Programação
*/


#include <bits/stdc++.h>
using namespace std;

// See if (i, j)is in range
// Fixes the program
bool inBounds(int i, int j) {
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}

bool bishopChecked(char board[][8], char bishop, int i, int j) {
    int k = 0;

    // Check the lower right diagonal
    while (inBounds(i + ++k, j + k)) {
        if (board[i + k][j + k] == bishop)
            return true;
        if (board[i + k][j + k] != '.')
            break;
    }


    k = 0; // Reset k for the next direction
    // Check the lower left diagonal
    while (inBounds(i + ++k, j - k)) {
        if (board[i + k][j - k] == bishop)
            return true;
        if (board[i + k][j - k] != '.')
            break;
    }

    k = 0;
    // Check the upper right diagonal
    while (inBounds(i - ++k, j + k)) {
        if (board[i - k][j + k] == bishop)
            return true;
        if (board[i - k][j + k] != '.')
            break;
    }

    k = 0;
    // Check the upper left diagonal
    while (inBounds(i - ++k, j - k)) {
        if (board[i - k][j - k] == bishop)
            return true;
        if (board[i - k][j - k] != '.')
            break;
    }

    return false;
}

bool rookChecked(char board[][8], char rook, int i, int j) {
    // Same logic as bishop but now we see run the line in which the king and the columm

    int k = 0;
    while (inBounds(i + ++k, j)) {
        if (board[i + k][j] == rook)
            return true;
        if (board[i + k][j] != '.')
            break;
    }
    k = 0;
    while (inBounds(i - ++k, j)) {
        if (board[i - k][j] == rook)
            return true;
        if (board[i - k][j] != '.')
            break;
    }
    k = 0;
    while (inBounds(i, j + ++k)) {
        if (board[i][j + k] == rook)
            return true;
        if (board[i][j + k] != '.')
            break;
    }
    k = 0;
    while (inBounds(i, j - ++k)) {
        if (board[i][j - k] == rook)
            return true;
        if (board[i][j - k] != '.')
            break;
    }
    return false;
}

// It needs for queen function
bool kingChecked(char board[][8], char king, int i, int j) {

    // Only options possible
    int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Check if it is in bound and if it is equal
    for (int k = 0; k < 8; k++) {
        int m = i + x[k];
        int n = j + y[k];

        if (inBounds(m, n) && board[m][n] == king)
            return true;
    }
    return false;
}

// Queen we only see if it is checked by the other pieces that have the same run to check
bool queenChecked(char board[][8], char c, int i, int j) {
    return bishopChecked(board, c, i, j) || rookChecked(board, c, i, j) || kingChecked(board, c, i, j);
}


bool knightChecked(char board[][8], char knight, int i, int j) {
    // Only positions possible
    int x[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int y[] = {1, -1, 1, -1, 2, -2, 2, -2};

    for (int k = 0; k < 8; k++) {
        int m = i + x[k];
        int n = j + y[k];

        if (inBounds(m, n) && board[m][n] == knight)
            return true;
    }
    return false;
}

bool pawChecked(char board[][8], char paw, int i, int j) {

    // See if paw is in the two options possible
    if (paw == 'P') {
        if (inBounds(i - 1, j - 1) && board[i - 1][j - 1] == 'p')
            return true;
        if (inBounds(i - 1, j + 1) && board[i - 1][j + 1] == 'p')
            return true;
    } else {
        if (inBounds(i + 1, j - 1) && board[i + 1][j - 1] == 'P')
            return true;
        if (inBounds(i + 1, j + 1) && board[i + 1][j + 1] == 'P')
            return true;
    }
    return false;
}


// NAO É UMA OPCAO!!!!!!!!! Alternativa nao acontece por si so mas ajuda na funcao queen, mas preciso tirar o k ou K para viabilizar
// bool kingCheck(char board[8][8], int posRow, int posCol, bool upper) {
//     // If king is 'K' (white) then opponent king is 'k' (black) and vice versa
//     cout << "Entra king" << endl;
//     char queen = upper ? 'q' : 'Q';
//     char opponentKing = upper ? 'k' : 'K';

//     // Loop neighboring square
//     for(int i = -1; i <= 1; i++) {
//         for(int j = -1; j <= 1; j++) {
//             // Don't check the square we are
//             if(!(i == 0 && j == 0) && posRow+i >= 0 && posRow+i < 8 && posCol+j >= 0 && posCol+j < 8) {
//                 if(board[posRow+i][posCol+j] == opponentKing || board[posRow+i][posCol+j] == queen) {
//                     return true; // King is checked by the other king
//                 }
//             }
//         }
//     }
//     return false;
// }


// Now we just reunite everything in a function
int checkBoard(char board[][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'k') { // k (black) is check
                if (knightChecked(board, 'N', i, j) || pawChecked(board, 'p', i, j) || rookChecked(board, 'R', i, j) ||
                    bishopChecked(board, 'B', i, j) || queenChecked(board, 'Q', i, j) || kingChecked(board, 'K', i, j))
                    return 2;
            }
            if (board[i][j] == 'K') { // K (white) is in check
                if (knightChecked(board, 'n', i, j) || pawChecked(board, 'P', i, j) || rookChecked(board, 'r', i, j) ||
                    bishopChecked(board, 'b', i, j) || queenChecked(board, 'q', i, j) || kingChecked(board, 'k', i, j))
                    return 1;
            }
        }
    }
    return 0;
}

int main() {
    // bool verif, upper; NAO FUNC

    int gameNo = 0;
    while (true) {
        char board[8][8];
        bool emptyBoard = true;

        // Read the boards
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cin >> board[i][j];
                if (board[i][j] != '.') {
                    emptyBoard = false;
                }
            }
        }

        if (emptyBoard) break;

        gameNo++;

        int result = checkBoard(board);
        cout << "Game #" << gameNo << ": ";

        switch(result) {
            case 0:
                cout << "no king is in check.";
                break;
            case 1:
                cout << "white king is in check.";
                break;
            case 2:
                cout << "black king is in check.";
                break;
        }
        cout << endl;

        // To handle the empty line between inputs
        string dummy;
        getline(cin, dummy);
    }

    return 0;
}
