/* Nome: Barbara Silveira Rodrigues
   Materia: Desafios de Programação
*/

#include <iostream>
#define MAX_STEPS 45
using namespace std;

int main(){

    int puzzle[4][4];
    int numCases, num;

    cin >> numCases;

    while(numCases--){
    
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cin >> num;
                puzzle[i][j] = num;
            }
        }

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cout << puzzle[i][j] << " ";
            }
            cout << endl;
        }
    cout << endl;
    }
}