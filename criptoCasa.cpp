#include <iostream>
#include <string>
#include <sstream>
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
    string word;
    string phrase;
    string paragraph;
    char decoded[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    char coded[26] = {'p', 'l', 'o', 'k', 'm', 'i', 'j', 'n', 'u', 'h', 'b', 'y', 'g', 'v',
                    't', 'f', 'c', 'r', 'd', 'x', 'e', 's', 'z', 'a', 'q', 'w'};
    cin >> numCases;
    cout << numCases;

    // Read the newline character left in the buffer
    string temp;
    getline(cin, temp);  // Consume the newline after numCases
    getline(cin, temp);  // Consume the blank line after numCases

   while(numCases != 0){
        phrase.clear();
        paragraph.clear();

        while(true){
            string line;
            getline(cin, line);

            if(line.empty()){
                break;
            }

            stringstream ss(line);
            phrase.clear();
            bool isPhraseApproved = true;
            while(ss >> word){
                cout << word << " ";
                word = decode(word, decoded, coded);
                if(approved(word) == true){
                    if(!phrase.empty()) phrase += " ";
                    phrase += word;
                } else {
                    isPhraseApproved = false;
                    break;
                }
            }
            cout << endl;

            if(isPhraseApproved) {
                if(!paragraph.empty()) paragraph += "\n";
                paragraph += phrase;
            } else {
                paragraph = "No solution.";
                break;
            }
            cout << endl;
        }
        cout << numCases;
        //cout << paragraph << endl;
        // Case is over
        numCases--;
    }

}