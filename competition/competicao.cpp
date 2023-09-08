/* Nome: Barbara Silveira Rodrigues
   Materia: Desafios de Programação
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Struct to represent each contestant
typedef struct {
    int id;
    int problemSolved; // Calculate how many problems were solved
    int time;
    int problems[10]; // vector to storage if the problem was solved or not
    int wrongAns[10]; // storage how many wrong answers a problem has
} contestors;

// Verify the answer given
int verifyAnswer(char answer) {
    if(answer == 'C') {
        return 1;
    } else if(answer == 'R' || answer == 'U' || answer == 'E') {
        return 0;
    } else {
        return 2;
    }
}

// Calculate the time spent of the contestant
int calculateTime(int time, int wrongs) {
    return time + wrongs * 20; // 20 is the penalty
}

// Print the output
void output(contestors contestant[], int tam) {
    for(int i = 0; i < tam; i++) {
        cout << contestant[i].id << " " << contestant[i].problemSolved << " " << contestant[i].time << endl;
    }
}

// Bubblesort to ordenate the array (code from previous work in AEDs II)
void order(contestors bd[], int tam) {
    contestors aux;
    for(int i = 0; i < tam; i++) {
        for(int j = i+1; j < tam; j++) {
            if(bd[j].problemSolved > bd[i].problemSolved ||
               (bd[j].problemSolved == bd[i].problemSolved && bd[j].time < bd[i].time) ||
               (bd[j].problemSolved == bd[i].problemSolved && bd[j].time == bd[i].time && bd[j].id < bd[i].id)) {
                aux = bd[i];
                bd[i] = bd[j];
                bd[j] = aux;
            }
        }
    }

    output(bd, tam);
}


int main() {
    // Variables
    contestors contestant[100];

    int numCases;

    cin >> numCases;

    // Read the newline character left in the buffer
    string temp;
    getline(cin, temp);  // Consume the newline after numCases
    getline(cin, temp);  // Consume the blank line after numCases

    for (int i = 0; i < numCases; ++i) {
        int size = 0;
        while (true) {
            string line;
            getline(cin, line);

            if (line.empty()) {
                order(contestant, size);
                cout << " " << endl; // after each competition
                break;
            }

            // stringstream makes it possible to use the line like a cin
            stringstream ss(line);
            int numCont, numProblem, time;
            char answer;

            // Read the line
            ss >> numCont >> numProblem >> time >> answer;

            // boolean so we know if the contestant is already computaded
            bool found = false;
            for(int i = 0; i < size && !found; i++) { // contestant is NOT new
                if(numCont == contestant[i].id) {
                    found = true;

                    if(contestant[i].problems[numProblem] != 1) { // Problem solved
                        if(verifyAnswer(answer) == 1) {
                            contestant[i].time += calculateTime(time, contestant[i].wrongAns[numProblem]);
                            contestant[i].problems[numProblem] = 1;
                            contestant[i].problemSolved++;
                        } else if(verifyAnswer(answer) == 2) { // Problem incorrect
                            contestant[i].wrongAns[numProblem]++;
                        }
                    }
                }
            }

            // Contestant is new
            if(!found) {
                contestors& current = contestant[size++]; // Add the new contestant
                current.id = numCont;
                current.problemSolved = 0;
                current.wrongAns[numProblem] = 0;

                if(verifyAnswer(answer) == 1) {
                    current.time = calculateTime(time, current.wrongAns[numProblem]);
                    current.problems[numProblem] = 1;
                    current.problemSolved++;
                } else if(verifyAnswer(answer) == 2) {
                    current.wrongAns[numProblem]++;
                }
            }
        }

    }
}


