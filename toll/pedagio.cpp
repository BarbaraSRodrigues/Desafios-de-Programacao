#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

typedef struct{
    string license;
    int day;
    int hour;
    string enter;
    int location;
} record;

// Aux function for the sorting
bool compareRecords(const record &a, const record &b) {
    if (a.license != b.license)
        return a.license < b.license;
    if (a.day != b.day)
        return a.day < b.day;
    return a.hour < b.hour;
}

int main(){

    // Variables
    int numCases, index = 0, aux;
    char twoPoints;
    record records[1000];
    string temp;

    getline(cin, temp);
    numCases = stoi(temp);

    for (int caseNum = 0; caseNum < numCases; caseNum++) {
        int prices[24];
        getline(cin, temp);
        stringstream ss(temp);

        // Read the prices
        for (int i = 0; i < 24; i++) {
            ss >> prices[i];
        }

        // Reset for each case
        index = 0;

        // Read the records
        while (true) {
            getline(cin, temp);
            if (temp.empty() || cin.eof()) {
                break;
            }

            ss.clear();
            ss.str(temp);

            ss >> records[index].license;
            ss >> aux >> twoPoints >> records[index].day >> twoPoints;
            ss >> records[index].hour >> twoPoints >> aux;
            ss >> records[index].enter >> records[index].location;
            index++;
        }

        // Sort the records by license, day and hour
        sort(records, records + index, compareRecords);

        // Use map to storage the billing
        map<string, int> bills;
        for (int i = 0; i < index - 1; i++) {
            // Check if it is a valid input
            if (records[i].license == records[i + 1].license && records[i].enter == "enter" && records[i + 1].enter == "exit") {
                // Calculate distance and cost (fare)
                int distance = abs(records[i].location - records[i + 1].location);
                int cost = distance * prices[records[i].hour] + 100;

                // bills will receive the
                bills[records[i].license] += cost;
                i++; // We work with two lines
            }
        }

        // Print the results
        for (const auto& [license, bill] : bills) {
            cout << license << " $" << (bill + 200) / 100 << ".";
            if ((bill + 200) % 100 < 10) cout << "0";
            cout << (bill + 200) % 100 << endl;
        }

        // endl between cases
        if (caseNum < numCases - 1) {
            cout << endl;
        }
    }
    return 0;
}
