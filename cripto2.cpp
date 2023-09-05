#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string decode(string coded, char arrayDecoded[], char arrayCoded[]){
    int size = coded.length();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 26; j++){
            if(coded[i] == arrayCoded[j]){
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

    for(int i = 1; i < n; i++){
        if(decoded[i] != decoded[0])
            return true;
    }
    return false;
}

int main(){
    int numCases;
    string word;
    string phrase;
    string paragraph;

    char decoded[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char coded[26] = {'p', 'l', 'o', 'k', 'm', 'i', 'j', 'n', 'u', 'h', 'b', 'y', 'g', 'v',
                    't', 'f', 'c', 'r', 'd', 'x', 'e', 's', 'z', 'a', 'q', 'w'};

    cin >> numCases;

    string temp;
    getline(cin, temp);  // Consume the newline after numCases

    while(numCases--){
        bool failedCase = false;
        paragraph = "";

        while(true){
            string line;
            getline(cin, line);

            if(line.empty()) {
                break; // Break if the line is empty, process next step after the loop
            }

            stringstream ss(line);
            string decodedLine = "";
            bool isDecodable = true;

            while(ss >> word){
                word = decode(word, decoded, coded);
                if(!approved(word)){
                    isDecodable = false;
                    break;
                }
                if(decodedLine != "") {
                    decodedLine += " ";
                }
                decodedLine += word;
            }

            if(isDecodable) {
                paragraph += decodedLine + "\n";
            } else {
                failedCase = true;
                break;
            }
        }

        if(failedCase || paragraph.empty()) {
            cout << "No solution." << endl;
        } else {
            cout << paragraph;
        }

        if(numCases > 0) cout << endl;  // separate cases
    }
}
