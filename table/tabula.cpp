/* Nome: Barbara Silveira Rodrigues
   Materia: Desafios de Programação
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float calculate(float a, float b, float c){
    float s = (a + b + c) / 2;  // Semi-perimeter
    float triangle_area = sqrt(s * (s - a) * (s - b) * (s - c));  // Area of the triangle
    float radius = (2 * triangle_area) / (a + b + c);  // Radius of the inscribed circle
    return radius;
}

int main(){
    float a, b, c;

    while(cin >> a >> b >> c){
        if((a == 0.0) && (b == 0.0) && (c == 0.0)){
            cout << "The radius of the round table is: 0.000" << endl;
        } else {
            cout << "The radius of the round table is: " << fixed << setprecision(3) << calculate(a, b, c) << endl;
        }
    }

    return 0;
}
