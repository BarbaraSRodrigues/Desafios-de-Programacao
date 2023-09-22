#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef struct{
    string license;
    int day;
    int hour;
    string enter;
    int location;
    int value;
} record;

/*  765DEF 01:01:05:59 enter 17
    765DEF 01:01:07:00 exit 95
    ABCD123 01:01:06:01 enter 17
    ABCD123 01:01:08:03 exit 95
*/

int main(){

    int numCases, index = 0, aux;
    char twoPoints; // Aux to dismiss the ":" that will be read 
    record records[1000];
    
    // Read number of cases
    cin >> numCases;

    string temp;
    getline(cin, temp);  // Consume the newline after numCases
    getline(cin, temp);  // Consume the blank line after numCases

    // Loop through numCases
    while(numCases != 0){

        // Get all the prices of the current case (month)
        int prices[24];
        for(int i=0;i < 24; i++){
            cin >> prices[i];
        }

        // Read to the struct
        string line;
        while(getline(cin, line)){
            stringstream ss(line);

            ss >> records[index].license;
            ss >> aux >> twoPoints >> records[index].day >> twoPoints;
            ss >> records[index].hour >> twoPoints >> aux;
            ss >> records[index].enter >> records[index].location;
            index++;
        }

        // Sort by lincense, day, hour

        // Calculate values

        // Cout everything
        numCases--;
    }

    return 0;
}