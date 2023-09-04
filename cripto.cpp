#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string decode(string coded, char arrayDecoded[], char arrayCoded[]){
    int size = coded.length();

    for(int i = 0; i < size; i++){
        for(int j = 0; j < 25; j++){
            if(coded[i] == arrayCoded[j]){
                // cout << "Coded: " << coded[i] << " Decoded: " << arrayDecoded[j] << endl; 
                coded[i] = arrayDecoded[j];
                break;
            }
        }
    }
    return coded;
} 

bool approved(string decoded){

    int n = decoded.length();
    for(int i = 1; i < n; i++){
        if(decoded[i] != decoded[0])
            return false;
    }
    return true;
}


int main(){


    // Variables
    int numCases;
    string word;
    string final[100];
    char decoded[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    char coded[26] = {'p', 'l', 'o', 'k', 'm', 'i', 'j', 'n', 'u', 'h', 'b', 'y', 'g', 'v',
                    't', 'f', 'c', 'r', 'd', 'x', 'e', 's', 'z', 'a', 'q', 'w'};
    cin >> numCases;

    // Read the newline character left in the buffer
    string temp;
    getline(cin, temp);  // Consume the newline after numCases
    getline(cin, temp);  // Consume the blank line after numCases

    while(numCases != 0){

        while(true){
            string line;
            getline(cin, line);

            if(line.empty()){
                cout << " " << endl; // after each case
                break;
            }

            stringstream ss(line);
            while(ss >> word){
                cout << word << " ";
                word = decode(word, decoded, coded);
                cout << word << " ";
            }
            //cout << endl;

            
            

        }


        

        // Case is over
        numCases--;
    }
}