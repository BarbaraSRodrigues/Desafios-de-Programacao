#include <iostream>
#include <string>
#include <algorithm> 
#include <cmath>
#define MAXDIGITS 100 /* maximum length bignum */
using namespace std;

typedef struct {
    char digits[MAXDIGITS]; 
    int lastdigit; 
} bignum;

int main(){

    // Variables 
    bignum *a, *b, *sum;
    string aux, aux2;
    int countNum = 0;

    // Allocate the bignums
    a = new bignum;
    b = new bignum;
    sum = new bignum;

    while(true){
        cin >> aux >> aux2;
        
        // Termination point
        if(aux == "0" && aux2 == "0")
            break;

        reverse(aux.begin(), aux.end()); 
        reverse(aux2.begin(), aux2.end());
        a->lastdigit = aux[aux.length()];
        b->lastdigit = aux2[aux2.length()];

        for(int i = 0; i < aux.length(); i++){
            a->digits[i] = aux[i];
        }

        for(int i = 0; i < aux2.length(); i++){
            b->digits[i] = aux2[i];
        }

        // Fibonacci
        
    }

    return 0;
}