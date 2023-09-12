#include <iostream>
using namespace std;

int main(){

    int max = 10, min = 0;
    int n, volume = 0;
    string phrase;


    cin >> n;
    for(int i = 0; i <= n; i++){
        cin.getline(phrase);
        if(phrase == "Skru op!"){
            if(volume != 10){
                volume++;
            }
        } else {
            if(volume != 0){
                volume--;
            }
        }
    }

    cout << volume;
}