#include <iostream>

using namespace std;
void computeTriangle(double a, double b, double c, double& area, double& per);

int main() {
    double side1, side2, side3, area, perimeter; 

    cout << "Enter the three lengths of the sides fo the triangle: "; 
    cin >> side1 >> side2 >> side3; 

    computeTriangle(side1, side2, side3, area, perimeter);

    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;

    return 0;
} 

void computeTriangle(double a, double b, double c, double& area, double& per) {
    per = a + b + c; 
    double s = per / 2; 
    area = sqrt(s * (s - a) * (s - b) * (s - c));
}