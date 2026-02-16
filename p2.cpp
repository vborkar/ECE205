#include <iostream>
#include <fstream>
#include <cmath> 

using namespace std;

double calculateAverage(int n1, int n2, int n3, int n4, int n5) {
    return (n1 + n2 + n3 + n4 + n5) / 5.0;
}

double calculateStdDev(int n1, int n2, int n3, int n4, int n5, double avg) {

    double sumOfSquares = pow(n1 - avg, 2) + pow(n2 - avg, 2) + 
                          pow(n3 - avg, 2) + pow(n4 - avg, 2) + 
                          pow(n5 - avg, 2);
    return sqrt(sumOfSquares / 5.0);
}

int main() {
    ifstream in; 
    ofstream out; 
    int n1, n2, n3, n4, n5;


    in.open("scores.txt");
    if (!in) {
        cout << "Error: Could not open scores.txt" << endl;
        return 1;
    }
    
    in >> n1; 
    in >> n2; 
    in >> n3;
    in >> n4;
    in >> n5; 

    double avg = calculateAverage(n1, n2, n3, n4, n5); 
    double std_dev = calculateStdDev(n1, n2, n3, n4, n5, avg);

    out.open("output.txt");
    
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);
    
    out << "Average: " << avg << endl; 
    out << "Standard Deviation: " << std_dev << endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The average score is: " << avg << endl;
    cout << "The standard deviation is: " << std_dev << endl;

    in.close();
    out.close();
    
    return 0;
}