/* Nome: Barbara Silveira Rodrigues
   Materia: Desafios de Programação
*/

#include <iostream>
#include <cmath>

using namespace std;


// Sum all digits
long sumDigits(long n) {
    long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Sum digits that are prime
long sumPrimeDigits(long n) {
    long sum = 0;
    // Count the number of 2s that divide n
    while (n % 2 == 0) {
        sum += sumDigits(2);
        n /= 2;
    }

    // Loop until the square root of n
    for (long i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            sum += sumDigits(i);
            n /= i;
        }
    }

    if (n > 2) {
        sum += sumDigits(n);
    }

    return sum;
}

// Check if it is prime or not
bool isPrime(long n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    long i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
        i += 6;
    }

    return true;
}

// Use the aux functions (above) to find the smith num
long findSmith(long n) {
    long num = n + 1;
    while (true) {
        if (!isPrime(num) && sumDigits(num) == sumPrimeDigits(num)) {
            return num;
        }
        ++num;
    }
}

int main() {
    int numCases;
    cin >> numCases;

    while (numCases--) {
        long n;
        cin >> n;
        cout << findSmith(n) << endl;
    }

    return 0;
}
