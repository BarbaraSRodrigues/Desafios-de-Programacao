/* Nome: Barbara Silveira Rodrigues
 * Materia: Desafios de Programacao
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string decode(string word, char keyboard[]){
    for(int i = 0; i < word.length(); i++){
        if(word[i] == '`' || word[i] == 'Q' || word[i] == 'A' || word[i] == 'Z'){
            // cout << "Achou igual!" << endl;
            word[i] = word[i];
        } else {
            for(int j = 0; j < 47; j++){
                if(word[i] == keyboard[j]){
                    // cout << "Achou a letra: " << word[i] << endl;
                    // cout << "Vai colocar a letra: " << keyboard[j-1] << endl;
                    word[i] = keyboard[j-1];
                    // cout << "Word tá recebendo: " << word[i] << endl;
                    break;
                }
            }
        }
    }
    // cout << "Palavra final: " << word << endl;
    return word;
}

int main(){

    // Variables 
    string line, word, phrase;
    char keyboard[47] = {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
                         'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\',
                         'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'',
                         'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'};

    while(getline(cin, line)){
        stringstream ss(line);
        while(ss >> word){
            word = decode(word, keyboard);
            phrase += word + " ";
        }
        cout << phrase << endl;
        phrase = "";
    }


    return 0;
}