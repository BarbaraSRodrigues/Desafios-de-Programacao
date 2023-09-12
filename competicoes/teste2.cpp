#include <iostream>
using namespace std;

int main() {
    int bricks, towers = 1;
    cin >> bricks;

    int pieces[bricks];

    for (int i = 0; i < bricks; i++) {
        cin >> pieces[i];
    }
  
    for(int i = 0; i < bricks-1; i++){
        if(pieces[i] < pieces[i+1]){
            towers++;
        }
    }

    cout << towers;

    return 0;
}
