#include <iostream>
#include <cmath> 
#include <iomanip>

using namespace std;

double m1; 
double m2; 
double d; 
double force; 
const double G = 6.673e-8;
bool continueCalculation = true;

// Function to calculate force 
double calculateForce(double m1, double m2, double d) {
    const double G = 6.673e-8; 
    return (G * m1 * m2) / pow(d, 2); 
}

int main() {
    char choice;
    do {
        double mass1, mass2, distance;
        cout << "Enter mass 1 (g), mass 2 (g), and distance (cm): ";
        cin >> mass1 >> mass2 >> distance;

        cout.setf(ios::scientific);
        cout.setf(ios::showpoint);
        cout.precision(2);

        force = calculateForce(mass1, mass2, distance);

        cout << "The gravitational attractive force is: " << force << " dynes" << endl;

    } while (continueCalculation);

    return 0;
}