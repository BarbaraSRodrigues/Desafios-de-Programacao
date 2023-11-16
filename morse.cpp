/* Nome: Barbara Silveira Rodrigues
   Materia: Desafios de Programação
*/

#include <iostream>
#include <algorithm> 
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

void decode(char lettersAndDiggits[], string morse[], string phrase){

    string decoded;
    bool found;

    for(int i = 0; i < phrase.length(); i++){
        for(int j = 0; j < 36; j++){
            if(toupper(phrase[i]) == lettersAndDiggits[j]){
                cout << "Letra: " << phrase[i] << endl;
                cout << "Vira: "  << morse[j] << endl;
                decoded += morse[j];
                cout << decoded << endl;
                break;
            }
        }
    }




    string reversed = decoded;
    reverse(reversed.begin(), reversed.end());
    
    cout << decoded << endl;
    reversed.pop_back();
    cout << reversed;

    if(decoded == reversed){
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
}


int main(){

    /*
    DOT = '0'
    LINE = '1'
    */
    
    string word, line, phrase;

    // Morse code library 
    char lettersAndDiggits[36] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'
                        ,'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'
                        ,'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    string morse[36] = {"01", "1000", "1010", "100", "0", "0010", "110"
                       ,"0000", "00", "0111", "101", "0100", "11", "10"
                       ,"111", "0110", "1101", "010", "000", "1", "001"
                       ,"0001", "011", "1001", "1011", "1100", "11111"
                       ,"10000", "00111", "00011", "00001", "00000"
                       ,"10000", "11000", "11100", "11110"};

    getline(cin, line);
    stringstream ss(line);
    while(ss >> word){
        phrase += word;
    }
    decode(lettersAndDiggits, morse, phrase);
}