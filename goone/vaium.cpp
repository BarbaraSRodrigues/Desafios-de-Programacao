/*
    Nome: Barbara Silveira Rodrigues
    Materia: Desafios de Programação
*/

#include <iostream>
using namespace std;

int main() {
    // Read input pairs
    while (true) {
        // Two unsigned integers to store the numbers (read normal when is a big number)
        unsigned long long a, b;

        cin >> a >> b;

        // Termination condition
        if (a == 0 && b == 0) {
            break;
        }

        int carry = 0; // Keeps track of the current carry from adding two digits
        int count = 0; // Keeps track of the number of carry operations

        while (a > 0 || b > 0 || carry > 0) {
            // Sum the least significant digits
            int sum = a % 10 + b % 10 + carry;

            // If the sum is more than 9, it means it goes one
            if (sum > 9) {
                count++;
                carry = 1;
            } else {
                // Reset carry
                carry = 0;
            }

            // Move to the next digit
            a /= 10;
            b /= 10;
        }

        // Print the result in the desired format
        if (count == 0) {
            cout << "No carry operation." << endl;
        } else {
            cout << count << " carry operation." << endl;
        }
    }
    return 0;
}