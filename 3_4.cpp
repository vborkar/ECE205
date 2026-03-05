#include <iostream>

using namespace std; 

void inputWeight(double& lbs, double& oz){
    cout << "Enter weight in pounds: ";
    cin >> lbs;
    cout << "Enter weight in ounces: ";
    cin >> oz;
}

void convertWeight(double lbs, double oz){
    int kg, g;
    double total_lbs = lbs + oz / 16.0;
    double total_kg = total_lbs * 0.453592;

    kg = total_kg * 1;
    g = (total_kg - kg) * 1000;
}

void outputWeight(int kg, int g){
    cout << "Weight in kilograms: " << kg << " kg and " << g << " g" << endl;
}

int main() {
    double lbs, oz;
    int kg, g;

    while(1){
        inputWeight(lbs, oz);
        convertWeight(lbs, oz);
        outputWeight(kg, g);
    }


    return 0;
}