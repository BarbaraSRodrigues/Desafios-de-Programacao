/* Nome: Barbara Silveira Rodrigues
 * Materia: Desafios de Programacao
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

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
        char crossword[n][m], auxChar;
        
        // Read the input given
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> auxChar;
                crossword[i][j] = toupper(auxChar); // Upper case is going to be the pattern
            }
        }

        // Read how many words we have and create a vector
        cin >> numWords;
        string words[numWords], auxWord;
        for(int i = 0; i < numWords; i++){
            cin >> auxWord;
            transform(auxWord.begin(), auxWord.end(), auxWord.begin(), ::toupper);
            words[i] = auxWord;
        }

        // We will get the "words" in columns, rows and diagonals 
        string wordsCol[m], wordsRow[n], wordsDiag[50];
        string aux;

        // "Words" in row
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                aux += crossword[i][j];
            }
            wordsRow[i] = aux;
            aux = "";
        }
        // "Words" in column
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                aux += crossword[i][j];
            }
            wordsRow[j] = aux;
            aux = "";
        }
        // "Words" in diagonal
        // Starting from the first row and moving down along the left
        for (int startRow = 0; startRow < n; startRow++) {
            int i = startRow, j = 0;
            while (i < n && j < m) {
                aux += crossword[i][j];
                i++;
                j++;
            }
            if (!aux.empty()) {
                wordsDiag[startRow] = aux;
                cout << wordsDiag[startRow] << endl;
                aux = "";
            }
        }
        // Starting from the first column and moving right along the top
        for (int startCol = 1; startCol < m; startCol++) {
            int i = 0, j = startCol;
            while (i < n && j < m) {
                aux += crossword[i][j];
                i++;
                j++;
            }
            if (!aux.empty()) {
                wordsDiag[n + startCol] = aux;
                cout << wordsDiag[n + startCol] << endl;
                aux = "";
            }
        }
                

        numCases--;
    }
}
