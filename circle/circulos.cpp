/*
    Nome: Barbara Silveira Rodrigues
    Materia: Desafios de Programação
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int numCases, numLines;
    float num, smallest;

    cin >> numCases;

    while(numCases != 0){
        
        cin >> numLines;
        vector<float> radii;
        for(int i = 0; i < numLines; i++){
            cin >> num;
            radii.push_back(num);
        }

        sort(radii.begin(), radii.end());

        do {
            // Calculate the rectangle

            // If the rectangle is smaller than the earlier rectangle then update the smallest
        } while(next_permutation(radii.begin(), radii.end()));

        numCases--;
    }
}