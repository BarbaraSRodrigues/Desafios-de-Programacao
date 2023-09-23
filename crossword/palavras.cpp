/* Nome: Barbara Silveira Rodrigues
 * Materia: Desafios de Programacao
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// Aux function for our findWord
bool is_valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

pair<int, int> findWord(int n, int m, vector<string> &crossword, string &word) {
    // Loop through crossword
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // If the current matches the first character of the word
            if (crossword[i][j] == word[0]) {
                // Check in all 8 directions (up, down, left, right, and the 4 diagonals)
                for (int dir = 0; dir < 8; ++dir) {
                    int len, x = i, y = j;
                    // Try to match the entire word in the current direction
                    for (len = 1; len < word.length(); ++len) {
                        x += dx[dir];
                        y += dy[dir];
                        // If we go out of bounds or doesn't match anymore
                        if (!is_valid(x, y, n, m) || crossword[x][y] != word[len]) break;
                    }
                    // If the entire word was matched in the current direction
                    if (len == word.length()) {
                        // Return the starting position
                        return {i + 1, j + 1};
                    }
                }
            }
        }
    }
    // If word not found (should not reach here)
    return {-1, -1};
}


int main(){

    int numCases, numWords;
    int n, m;

    cin >> numCases;

    while(numCases != 0){

        string temp;
        getline(cin, temp);  // Consume the newline after numCases
        getline(cin, temp);  // Consume the blank line after numCases

        cin >> n;
        cin >> m;

        // If the n and m passed is not correct
        if((m < 1) || (n > 50))
            break;

        // Create a matrix for every char and an aux char
        vector<string> crossword(n);
        char auxChar;

        // Read the input given
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> auxChar;
                crossword[i][j] = toupper(auxChar); // Upper case is going to be the pattern
            }
        }

        // Read how many words we have and compare
        cin >> numWords;
        for (int i = 0; i < numWords; ++i) {
            string word;
            cin >> word;
            transform(word.begin(), word.end(), word.begin(), ::toupper);
            pair<int, int> pos = findWord(n, m, crossword, word);
            cout << pos.first << " " << pos.second << endl;
        }

        // We will get the "words" in columns, rows and diagonals
        // string wordsCol[m], wordsRow[n], wordsDiag[50];
        // string aux; NAO FUNC



        if (numCases > 1) cout << endl;
        numCases--;
    }
}