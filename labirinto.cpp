#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 225; 

int main() {
    int w, h, numMaze = 0;
    
    while (true) {
        cin >> w >> h;
        
        if ((w == 0) && (h == 0))
            break;
        
        vector<vector<int>> maze(MAX_SIZE, vector<int>(MAX_SIZE, 0));
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
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
        for (int i = 0; i < w * 3; i++) {
            for (int j = 0; j < h * 3; j++) {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        numMaze++;
    }

    return 0;
}
