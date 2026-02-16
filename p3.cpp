#include <iostream>
#include <iomanip>

using namespace std;


double calculateHatSize(double weight, double height) {
    return (2.9 *weight) / height;
}

double calculateJacketSize(double height, double weight, int age) {
    double baseSize = (height *weight) / 288.0;
    double adjustment = 0.0;
    
    if (age > 30) {
        int fullDecades = (age - 30) / 10;
        adjustment = fullDecades *0.125; 
    }
    
    return baseSize + adjustment;
}

double calculateWaistSize(double weight, int age) {
    double baseSize = weight / 5.7;
    double adjustment = 0.0;
    
    if (age > 28) {
        int fullIntervals = (age - 28) / 2;
        adjustment = fullIntervals *0.1; 
    }
    
    return baseSize + adjustment;
}

int main() {
    double height, weight;
    int age;

    cout << "Enter your height (in inches), weight (in pounds), and age: ";
    cin >> height >> weight >> age;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "\n--- Your Calculated Clothing Sizes ---" << endl;
    cout << "Hat Size:    " << calculateHatSize(weight, height) << endl;
    cout << "Jacket Size: " << calculateJacketSize(height, weight, age) << " inches" << endl;
    cout << "Waist Size:  " << calculateWaistSize(weight, age) << " inches" << endl;

    return 0;
}