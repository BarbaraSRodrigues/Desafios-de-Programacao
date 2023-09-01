#include <iostream>
using namespace std;


typedef struct informations{
    int id;
    int problemSolved;
    int time;
    int problems[10];
    int wrongAns;
}contestors;

int verifyAnswer(char answer){
    if((answer == 'C')){
        return 1;
    } else if((answer == 'R') || (answer == 'U') || (answer = 'E')){
        return 0;
    } else {
        return 2;
    }
}

int calculateTime(int time, int wrongs){
    return time + wrongs * 20;
}

// Using bubblesort from previous works (AEDs II)
void order(contestors *bd[], contestors*BDOrd[], int tam)
{
    int realTam = tam < 50 ? tam : 50;
    
    for(int i = 0; i < realTam; i++)
    {
      BDOrd[i] = bd[i];  
    }

    contestors *aux; 
    for(int i = 0; i < tam; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if((BDOrd[j]->problemSolved > BDOrd[i]->problemSolved) || 
               (BDOrd[j]->problemSolved == BDOrd[i]->problemSolved && BDOrd[j]->time < BDOrd[i]->time) ||
               (BDOrd[j]->problemSolved == BDOrd[i]->problemSolved && BDOrd[j]->time == BDOrd[i]->time && BDOrd[j]->id < BDOrd[i]->id))
            {
                aux = BDOrd[i];
                BDOrd[i] = BDOrd[j];
                BDOrd[j] = aux;          
            }
        }
    }

    output(BDOrd, tam);
}

void output(contestors *contestant[], int tam){
    for(int i = 0; i < tam;i++){
        cout << contestant[i]->id << " " << contestant[i]->problemSolved << " " << contestant[i]->time << endl; 
    }
}


int main(){

    // Declaring the struct
    contestors *contestant[100]; 
    contestors *contestantOrd[100]; // Ordenaded

    // Variables readable
    int numCases, numCont, numProblem, time;
    char answer;

    // Variables aux
    bool wasAdded;
    int size = 0;

    cin >> numCases;
    cin >> numCont >> numProblem >> time >> answer;

    for(int i = 0; i < 100; i++){
        if(numCont == contestant[i]->id){
            wasAdded = false;

            // Verify if the problem was already solved
            if(contestant[i]->problems[numProblem] == 1)
                break;
            
            // Do the operations
            if(verifyAnswer(answer) == 1){
                contestant[i]->time = calculateTime(time, contestant[i]->wrongAns);
                contestant[i]->problems[numProblem] = 1;
                contestant[i]->problemSolved++; 
            } else if(verifyAnswer(answer) == 0){
                break;
            } else {
                contestant[i]->wrongAns++;
            }
        }
    }

    if(wasAdded == false){        
        // Add to the list of structs
        contestant[size]->id = numCont;
        contestant[size]->problemSolved = 0;
        contestant[size]->wrongAns = 0;
        size++;

        if(verifyAnswer(answer) == 1){
            contestant[size]->time = calculateTime(time, contestant[size]->wrongAns);
            contestant[size]->problems[numProblem] = 1;
            contestant[size]->problemSolved++; 
        } else if(verifyAnswer(answer) == 0){
            return;
        } else {
            contestant[size]->wrongAns++;
        }
    }

    order(contestant, contestantOrd, size);
}
