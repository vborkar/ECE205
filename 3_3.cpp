#include <iostream>

using namespace std;

int calculateDuration(int start, int end){
    int startTotal = (start / 100) * 60 + (start % 100); 
    int endTotal = (end / 100) * 60 + (end % 100);

    if (endTotal < startTotal) {
        endTotal += 1440;  // to account if end is before start -- this means there is an extra 24 hours 
    }

    return endTotal - startTotal;
}

int main() {
    int start, end;

    cout << "Enter the start time in 24-hour format (HHMM): ";
    cin >> start;
    cout << "Enter the end time in 24-hour format (HHMM): ";
    cin >> end;

    int duration = calculateDuration(start, end);
    cout << "Difference in time in minutes: " << duration << endl;

    return 0;
}