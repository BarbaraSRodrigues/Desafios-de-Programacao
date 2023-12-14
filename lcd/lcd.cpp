#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX 1000

void print(vector<string>& table, char c, int s, int x) {
    for (int cul = x; cul <= x + s + 1; cul++) {
        for (int row = 0; row <= 2 * s + 2; row++) {
            if (cul == x || cul == x + s + 1) {
                if ((row >= 1 && row <= s) || (row >= s + 2 && row <= 2 * s + 1))
                    table[row][cul] = '|';
                else
                    table[row][cul] = ' ';
            } else {
                if ((row >= 1 && row <= s) || (row >= s + 2 && row <= 2 * s + 1))
                    table[row][cul] = ' ';
                else
                    table[row][cul] = '-';
            }
        }
    }

    switch (c) {
        case '0':
            for (int cul = x + 1; cul <= x + s; cul++)
                table[s + 1][cul] = ' ';
            break;
        case '1':
            for (int row = 1; row <= 2 * s + 2; row++)
                table[row][x] = ' ';
            for (int cul = x + 1; cul <= x + s; cul++)
                table[0][cul] = table[s + 1][cul] = table[2 * s + 2][cul] = ' ';
            break;
        case '2':
            for (int row = 1; row <= s; row++)
                table[row][x] = ' ';
            for (int row = s + 2; row <= 2 * s + 1; row++)
                table[row][x + s + 1] = ' ';
            break;
        case '3':
            for (int row = 1; row <= 2 * s + 1; row++)
                table[row][x] = ' ';
            break;
        case '4':
            for (int cul = x; cul <= x + s + 1; cul++)
                table[0][cul] = table[2 * s + 2][cul] = ' ';
            for (int row = s + 2; row <= 2 * s + 1; row++)
                table[row][x] = ' ';
            break;
        case '5':
            for (int row = 1; row <= s; row++)
                table[row][x + s + 1] = ' ';
            for (int row = s + 2; row <= 2 * s + 1; row++)
                table[row][x] = ' ';
            break;
        case '6':
            for (int row = 1; row <= s; row++)
                table[row][x + s + 1] = ' ';
            break;
        case '7':
            for (int row = 1; row <= 2 * s + 1; row++)
                table[row][x] = ' ';
            for (int cul = x + 1; cul <= x + s; cul++)
                table[s + 1][cul] = table[2 * s + 2][cul] = ' ';
            break;
        case '8':
            break;
        case '9':
            for (int row = s + 2; row <= 2 * s + 1; row++)
                table[row][x] = ' ';
            break;
    }
}

int main() {
    int s;
    char str[MAX];

    while (cin >> s >> str) {
        if (s == 0 && (str[0] == '0' && str[1] == '\0'))
            break;

        vector<string> table(2 * s + 3, string(MAX, ' '));

        int cul = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            print(table, str[i], s, cul);
            cul += s + 3;
        }

        for (int row = 0; row <= 2 * s + 2; row++) {
            std::cout << table[row] << '\n';
        }

        std::cout << '\n';
    }

    return 0;
}
