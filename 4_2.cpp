//**Write a program for judging a diving competition. The program will take
// as input a degree of difficultyand 7 judges’ scores from the console 
// (store in array). The scores are between 0 and 10 and can be a real number.
//The highest and lowest scores input are thrown out and the remaining scores 
//are added together. The sum is thenmultiplied by the degree of difficulty 
//of a dive, which ranges from 1.2 to 3.8 points. The result is then multiplied
//by 0.6 to determine the diver’s score. Test your code with multiple inputs and 
//ensure that the program forces allinputs to be within the allowable data ranges.*/

#include <iostream>
using namespace std;
 
const int NUM_JUDGES = 7;
 
void getScores(double scores[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter score for judge " << i + 1 << " (0.0 - 10.0): ";
        cin >> scores[i];
        while (scores[i] < 0.0 || scores[i] > 10.0) {
            cout << "Invalid. Enter a score between 0.0 and 10.0: ";
            cin >> scores[i];
        }
    }
}
 
int findMinIndex(double scores[], int n) {
    int minIdx = 0;
    for (int i = 1; i < n; i++)
        if (scores[i] < scores[minIdx]) minIdx = i;
    return minIdx;
}
 
int findMaxIndex(double scores[], int n) {
    int maxIdx = 0;
    for (int i = 1; i < n; i++)
        if (scores[i] > scores[maxIdx]) maxIdx = i;
    return maxIdx;
}
 
double computeFinalScore(double scores[], int n, double difficulty) {
    int minIdx = findMinIndex(scores, n);
    int maxIdx = findMaxIndex(scores, n);
 
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        if (i == minIdx || i == maxIdx) continue;
        sum += scores[i];
    }
 
    return sum * difficulty * 0.6;
}
 
int main() {
    double scores[NUM_JUDGES];
    double difficulty;
 
    cout << "Enter degree of difficulty (1.2 - 3.8): ";
    cin >> difficulty;
    while (difficulty < 1.2 || difficulty > 3.8) {
        cout << "Invalid. Enter difficulty between 1.2 and 3.8: ";
        cin >> difficulty;
    }
 
    getScores(scores, NUM_JUDGES);
 
    int minIdx = findMinIndex(scores, NUM_JUDGES);
    int maxIdx = findMaxIndex(scores, NUM_JUDGES);
    cout << "\nDropped lowest score: " << scores[minIdx]
         << " (Judge " << minIdx + 1 << ")\n";
    cout << "Dropped highest score: " << scores[maxIdx]
         << " (Judge " << maxIdx + 1 << ")\n";
 
    double finalScore = computeFinalScore(scores, NUM_JUDGES, difficulty);
    cout << "Diver's final score: " << finalScore << "\n";
 
    return 0;
}