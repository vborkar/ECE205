#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int input_time; 
int hours;
int minutes;
int seconds;

float real_hour;
float real_minute;

int main() {
    cout << "Enter time in seconds: " << endl;
    cin >> input_time;
    cout << endl;

    hours = input_time / 3600;
    minutes = (input_time % 3600) / 60;
    seconds = input_time % 60;

    real_hour = float(hours) + float(minutes / 60.0) + float(seconds / 3600.0);
    real_minute = float(hours * 60) + float(minutes) + float(seconds / 60.0);

    cout << "Time is " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds." << endl;

    cout << fixed << setprecision(4); 

    cout << "Real time in hours is: " << real_hour << " hours." << endl;
    cout << "Real time in minutes is: " << real_minute << " minutes." << endl;

    return 0;
}
