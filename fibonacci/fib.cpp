/*
    Nome: Barbara Silveira Rodrigues
    Materia: Desafios de Programação
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define MAXDIGITS 101
using namespace std;

typedef struct {
    char digits[MAXDIGITS];
    int lastdigit;
} bignum;

// Vector to store fibonacci numbers
vector<bignum> precomputedFib;

// Initialize the bignum
void initialize(bignum &b) {
    for(int i = 0; i < MAXDIGITS; i++)
        b.digits[i] = 0;
    b.lastdigit = 0;
}

// Function to add two bignums
bignum add(bignum &a, bignum &b) {
    bignum result;
    initialize(result);
    int carry = 0;
    for(int i = 0; i < MAXDIGITS; i++) {
        int sum = a.digits[i] + b.digits[i] + carry;
        result.digits[i] = sum % 10;
        carry = sum / 10;
    }
    result.lastdigit = a.lastdigit > b.lastdigit ? a.lastdigit : b.lastdigit;
    if (carry > 0)
        result.digits[++result.lastdigit] = carry;
    return result;
}

int compare(bignum &a, bignum &b) {
    for(int i = MAXDIGITS - 1; i >= 0; i--) {
        if(a.digits[i] > b.digits[i])
            return 1;
        else if(a.digits[i] < b.digits[i])
            return -1;
    }
    return 0;
}

// Calculate fibonacci numbers
void precomputeFibonacci() {
    bignum first, second, next;
    initialize(first);
    initialize(second);
    initialize(next);

    first.digits[0] = 1;
    second.digits[0] = 2;

    // Store inside the vector the first and second numbers
    precomputedFib.push_back(first);
    precomputedFib.push_back(second);

    while(true) {
        // Compute the fibonacci
        next = add(first, second);

        // Breaks the loop if exceeds the max
        if(next.lastdigit == MAXDIGITS - 1 && next.digits[MAXDIGITS - 1] > 0)
            break;

        // Store inside the
        precomputedFib.push_back(next);

        // Move forward
        first = second;
        second = next;
    }
}

int main(){

    // Variables
    bignum a, b;
    string aux, aux2;
    int countNum;

    precomputeFibonacci();

    while(true) {
        cin >> aux >> aux2;

        // Termination condition
        if(aux == "0" && aux2 == "0")
            break;

        // Reverse the string that represents the number
        reverse(aux.begin(), aux.end());
        reverse(aux2.begin(), aux2.end());

        // Initialize and define the last digit of the bignum digiti
        initialize(a);
        initialize(b);
        a.lastdigit = aux.length() - 1;
        b.lastdigit = aux2.length() - 1;

        // Store inside digits each char inside the aux string
        for(int i = 0; i < aux.length(); i++)
            a.digits[i] = aux[i] - '0';

        for(int i = 0; i < aux2.length(); i++)
            b.digits[i] = aux2[i] - '0';

        countNum = 0;

        // Loop through each fibonacci number stored
        for(bignum &fibNum : precomputedFib) {
            // If fibNum is in the range we increment the countNum
            if(compare(fibNum, a) >= 0 && compare(fibNum, b) <= 0) {
                countNum++;
            }
        }

        cout << countNum << endl;
    }

    return 0;
}
