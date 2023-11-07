/* Nome: Barbara Silveira Rodrigues
   Materia: Desafios de Programação
*/

#include <iostream>

using namespace std;

// Maze size
#define MAXMAZE 150

// Maze definition (/ or \)
#define EMPTY 0
#define SLASH 1
#define BACKSLASH 2
#define VISITED 3

// Maze directions
#define LEFT_UP 0
#define UP 1
#define RIGHT_UP 2
#define LEFT 3
#define RIGHT 4
#define LEFT_BOTTOM 5
#define DOWN 6
#define RIGHT_BOTTOM 7

// Struct used for the maze
struct mazes
{
    int status[MAXMAZE][MAXMAZE];
    int width, height;
};

// Possible directions
int length;
int offset[8][2] = { { -1, -1}, { -1, 0}, { -1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0},
    {1, 1}
};

inline bool inBounds(int line, int row, int width, int height)
{
    return ((0 <= line && line < height) && (0 <= row && row < width));
}

// DFS to see the visited and find the cycles
void floodFill(mazes *maze, int line, int row)
{
    length++;
    maze->status[line][row] = VISITED;

    for (int d = LEFT_UP; d <= RIGHT_BOTTOM; d++)
    {
        int tline = line + offset[d][0];
        int trow = row + offset[d][1];

        if (inBounds(tline, trow, maze->width, maze->height)){
            if (maze->status[tline][trow] == EMPTY)
            {
                if (tline == line || trow == row)
                    floodFill(maze, tline, trow);
                else
                {
                    if (d == LEFT_UP)
                        if (maze->status[line][row - 1] != SLASH)
                            floodFill(maze, tline, trow);
                    if (d == RIGHT_BOTTOM)
                        if (maze->status[line][row + 1] != SLASH)
                            floodFill(maze, tline, trow);
                    if (d == LEFT_BOTTOM)
                        if (maze->status[line][row - 1] != BACKSLASH)
                            floodFill(maze, tline, trow);
                    if (d == RIGHT_UP)
                        if (maze->status[line][row + 1] != BACKSLASH)
                            floodFill(maze, tline, trow);
                }
            }
        }
    }
}

int main(int ac, char *av[])
{
    mazes maze;
    int width, height, cases = 1;
    char slash;
    bool isBackslash;

    while (cin >> width >> height, width && height)
    {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
            {
                cin >> slash;

                isBackslash = (slash == '\\');
                maze.status[i * 2][j * 2] = isBackslash ? BACKSLASH : EMPTY;
                maze.status[i * 2][j * 2 + 1] = isBackslash ? EMPTY : SLASH;
                maze.status[i * 2 + 1][j * 2] = isBackslash ? EMPTY : SLASH;
                maze.status[i * 2 + 1][j * 2 + 1] = isBackslash ? BACKSLASH : EMPTY;
            }

        maze.width = 2 * width;
        maze.height = 2 * height;

        for (int i = 0; i < maze.height; i++)
            for (int j = 0; j < maze.width; j++)
                if (maze.status[i][j] == EMPTY)
                    if (i == 0 || j == 0 || i == (maze.height - 1)
                            || j == (maze.width - 1))
                        floodFill(&maze, i, j);

        int max = 0, cycles = 0;
        for (int i = 0; i < maze.height; i++)
            for (int j = 0; j < maze.width; j++)
                if (maze.status[i][j] == EMPTY)
                {
                    cycles++;

                    length = 0;
                    floodFill(&maze, i, j);

                    if (max < length)
                        max = length;
                }

        // Show the result found
        cout << "Maze #" << cases++ << ":" << endl;
        if (max > 0)
        {
            cout << cycles << " Cycles; the longest has length " << max << ".";
        }
        else
            cout << "There are no cycles.";
        cout << endl << endl;
    }

    return 0;
}