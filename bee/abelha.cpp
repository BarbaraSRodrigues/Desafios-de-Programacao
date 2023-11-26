/* Nome: Barbara Silveira Rodrigues
   Materia: Desafios de Programação
*/

#include <iostream>
using namespace std;

// Global variables
int varv, willis , x, y;

void decode()
{
    while(true)
    {
        // First option (0 0)
        if(willis == 1)
            return;

        varv++;
        y++;
        willis--;

        // First option
        if(willis == 1)
            return;

        // Move diagonally left and up
        for (int i = 0; i < varv -1; i++) {
            x--;
            y++;
            if(--willis == 1)
                return;
        }

        // Move horizontally left
        for (int i = 0; i < varv; i++) {
            x--;
            if(--willis == 1)
                return;
        }

        // Move vertically down
        for (int i = 0; i < varv; i++) {
            y--;
            if(--willis == 1)
                return;
        }

        // Move diagonally right and down
        for (int i = 0; i < varv; i++) {
            x++;
            y--;
            if(--willis == 1)
                return;
        }

        // Move horizontally right
        for (int i = 0; i < varv; i++) {
            x++;
            if(--willis == 1)
                return;
        }

        // Move vertically up
        for (int i = 0; i < varv; i++) {
            y++;
            if( --willis == 1)
                return;
        }
    }
}

int main()
{
    while(cin >> willis)
    {
        varv = 0;
        x = 0;
        y = 0;

        decode();

        cout << x << " " << y << endl;
    }
    return 0;
}