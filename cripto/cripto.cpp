/* Nome: Barbara Silveira Rodrigues
 * Materia: Desafios de Programacao
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string decode(string coded, char arrayDecoded[], char arrayCoded[]){
    int size = coded.length();

    for(int i = 0; i < size; i++){
        for(int j = 0; j < 26; j++){
            if(coded[i] == arrayCoded[j]){
                // cout << "Coded: " << coded[i] << " Decoded: " << arrayDecoded[j] << endl; // debug
                coded[i] = arrayDecoded[j];
                break;
            }
        }
    }
    return coded;
}

bool approved(string decoded){
    int n = decoded.length();

    if(n == 1) return false;

    // Check if all characters are the same
    for(int i = 1; i < n; i++){
        if(decoded[i] != decoded[0])
            return true;  // Found a different character
    }

    return false;  // All characters are the same so not approved
}

int main(){


    // Variables
    int numCases;
    int emptyLine = 0;
    int invalidCase = 0;
    string word;
    string phrase = "";
    string paragraph = "";
    char decoded[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    char coded[26] = {'p', 'l', 'o', 'k', 'm', 'i', 'j', 'n', 'u', 'h', 'b', 'y', 'g', 'v',
                    't', 'f', 'c', 'r', 'd', 'x', 'e', 's', 'z', 'a', 'q', 'w'};
    cin >> numCases;

    // Read the newline character left in the buffer
    string temp;
    getline(cin, temp);  // Consume the newline after numCases
    getline(cin, temp);  // Consume the blank line after numCases

    while (numCases != 0) {
        vector<string> allPhrases;  // To store all the phrases of the case
        bool caseIsValid = true;   // For the entire case
        
        while (true) {
            string line;
            bool lineIsValid = true;  // For the current line
            getline(cin, line);

            if (line.empty()) {
                // cout << "Linha vazia!" << endl;
                emptyLine++;
                break;
            }
                        
            string phrase = "";
            stringstream ss(line);
            while (ss >> word) {
                emptyLine = 0;
                if (approved(word)) {
                    word = decode(word, decoded, coded);
                    phrase += word + " ";
                } else {
                    lineIsValid = false;
                    caseIsValid = false;  // Mark the entire case as invalid
                    break;
                }
            }
            if (lineIsValid) {
                allPhrases.push_back(phrase);  // Store the phrase for the case
            }
        }

        if(emptyLine > 1){
            invalidCase++;
            caseIsValid = false;
            emptyLine = 0;
        }

        if (caseIsValid) {
            // If the case is valid print all the stored phrases
            for (const auto& ph : allPhrases) {
                cout << ph << endl;
            }
        } else {
            invalidCase++;
            if(invalidCase > 2){
                cout << "No solution.";
                invalidCase = 0;
            } else {
                cout << "No solution." << endl;
            }
        }

        if (numCases > 1) {
            cout << endl;
        }   
        numCases--;
    }
}