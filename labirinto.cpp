#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){

    int w, h, numMaze = 0;
    char aux;

    while(true){
        cin >> w >> h;
        int maze[w*3][h*3];

        if((w == 0) && (h == 0))
            break;
        
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                char aux;
                cin >> aux;

                if(aux == '/'){
                    maze[i*3][j*3] = 0;
                    maze[i*3][j*3+1] = 0;
                    maze[i*3][j*3+2] = 1;

                    maze[i*3+1][j*3] = 0;
                    maze[i*3+1][j*3+1] = 1;
                    maze[i*3+1][j*3+2] = 0;

                    maze[i*3+2][j*3] = 1;
                    maze[i*3+2][j*3+1] = 0;
                    maze[i*3+2][j*3+2] = 0;
                } else {
                    maze[i*3][j*3] = 1;
                    maze[i*3][j*3+1] = 0;
                    maze[i*3][j*3+2] = 0;

                    maze[i*3+1][j*3] = 0;
                    maze[i*3+1][j*3+1] = 1;
                    maze[i*3+1][j*3+2] = 0;

                    maze[i*3+2][j*3] = 0;
                    maze[i*3+2][j*3+1] = 0;
                    maze[i*3+2][j*3+2] = 1;
                }
            }
        }

        // Displaying the maze for testing
        for(int i = 0; i < w*3; i++){
            for(int j = 0; j < h*3; j++){
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        numMaze++;
    }

    return 0;
}