#include <iostream>
#include <iomanip>

using namespace std;

void input(int& hours, int& minutes);
void conversion(int& hours, char& ap);
void output(int hours, int minutes, char ap);

int main() {
    int hours, minutes;
    char ap;
    while (1){
        input(hours, minutes);
        conversion(hours, ap);
        output(hours, minutes, ap);
    } 

    return 0;
}

void input(int& hours, int& minutes) {
    cout << "Enter hours (00 - 23): ";
    cin >> hours;
    cout << "Enter minutes (00 - 59): ";
    cin >> minutes;
}

void conversion(int& hours, char& ap) {
    if (hours >= 12) {
        ap = 'P';
        hours = hours - 12;
    } else {
        ap = 'A';
    }
}

void output(int hours, int minutes, char ap) {
    cout << "Time in 12-hour format: "  << hours << ":" << setfill('0') << setw(2) << minutes << " " << ap << "M" << endl;
}