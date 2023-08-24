#include <iostream>
using namespace std;

/* Nome: Barbara Silveira Rodrigues
 * RA: 2021.1.08.042
 * Materia: Desafios de Programacao
*/

int main(){

    // Variables
    long int n, i, j;
    int count = 0, max = 0;

    while(cin >> i >> j){

        int aux1 = i, aux2 = j; 

        // The first input is greater than the second than we swap it
        if(i > j){
            long int aux = i;
            i = j;
            j = aux;
        }

        // Loop between i and j
        for (long int x = j; x >= i; x--) {
            n = x;
            // Loop to get the length and to do the operations
            while (n != 1) {
                if (n % 2 == 0) {
                    n = n / 2;
            } else {
                n = n * 3 + 1;
            }
            count++;
            }
        count++; // Include the j
        if(count > max) // Update the max cycle
            max = count;
        count = 0; // Start the count all over again
        }

        cout << aux1 << " " << aux2 << " " << max << endl; 
        max = 0; // Reboot
    }

}