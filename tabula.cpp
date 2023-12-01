/* Nome: Barbara Silveira Rodrigues
   Materia: Desafios de Programação
*/

#include <iostream>
#include <cmath>
using namespace std;

float calculate(float a, float b, float c){
    float s, aux, aux2, areaADB, areaBDC, areaADC, radius;

    s = 0.5 * (a + b + c);
    aux = s * (s-a) * (s-b) * (s-c);
    aux2 = sqrt(aux);

    areaADB = 0.5 * c;
    areaBDC = 0.5 * b;
    areaADC = 0.5 * a;

    radius = (areaADB + areaBDC + areaADC) / aux2;
    return radius;
}

int main(){

    float a, b, c;

    while(cin >> a >> b >> c){
       cout << "The radius of the round table is: " << calculate(a, b, c) << endl;
    }

    return 0;
}