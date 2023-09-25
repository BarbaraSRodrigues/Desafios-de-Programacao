/* Nome: Barbara Silveira Rodrigues
   Materia: Desafios de Programação
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Aux function to check for the palindrome
bool checkPalindrome(int number) {
    int aux, reversed = 0, original;
    original = number;

    while(number != 0) {
        aux = number % 10;
        reversed = reversed * 10 + aux;
        number /= 10;
    }

    if(original == reversed) {
        return true;
    } else {
        return false;
    }
}

// Reverse an int
int reverseNum(int number) {
    int aux, reversed = 0;

    while(number != 0) {
        aux = number % 10;
        reversed = reversed * 10 + aux;
        number /= 10;
    }
    return reversed;
}

int main() {
    // Variables
    int numTest, current, sum, sumIndex, reversed;

    cin >> numTest;
    int numbers[numTest];

    // Read all the numbers
    for(int i = 0; i < numTest; i++) {
        cin >> numbers[i];
    }

    // Iterate through each number
    for(int i = 0; i < numTest; i++) {
        // First case
        sum = numbers[i];
        sumIndex = 0;

        // Check the palindrome and the sumIndex shouldn't be over 1000 (196 example)
        while(!checkPalindrome(sum) && sumIndex < 1000) {
            sum += reverseNum(sum);
            sumIndex++;
        }

        cout << sumIndex << " " << sum << endl;
    }
    return 0;
}
