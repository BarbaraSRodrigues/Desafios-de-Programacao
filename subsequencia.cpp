/* Nome: Barbara Silveira Rodrigues
 * Materia: Desafios de Programacao
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void subsequence(string phrase, string word){

    vector<bool> verified(phrase.length());
    int count = 0;
    
    

}


int main(){

    int numCases;
    string phrase, word;

    cin >> numCases;

    while(numCases--){
        cin >> phrase, word;
        subsequence(phrase, word);
    }


}