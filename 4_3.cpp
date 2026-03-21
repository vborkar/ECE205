// Homework 4 Problem 3 

#include <iostream>
using namespace std;
 
const int ROWS = 10;
const int COLS = 4;
const char SEAT_LABELS[COLS] = {'A', 'B', 'C', 'D'};
 
void first_seats(char seats[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            seats[r][c] = SEAT_LABELS[c];
}
 
void display(char seats[ROWS][COLS]) {
    cout << "\n--- Seat Map ---\n";
    for (int r = 0; r < ROWS; r++) {
        cout << r + 1 << "\t";
        for (int c = 0; c < COLS; c++)
            cout << seats[r][c] << " ";
        cout << "\n";
    }
}
 
bool allSeatsTaken(char seats[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            if (seats[r][c] != 'X') return false;
    return true;
}
 
int colIndex(char letter) {
    for (int i = 0; i < COLS; i++)
        if (SEAT_LABELS[i] == letter) return i;
    return -1;
}
 
void bookSeat(char seats[ROWS][COLS]) {
    int row;
    char col;
    bool valid = false;
 
    while (!valid) {
        cout << "Enter seat row (1-10) and column (A-D): ";
        cin >> row >> col;
        col = toupper(col);
 
        int r = row - 1;
        int c = colIndex(col);
 
        if (r < 0 || r >= ROWS || c == -1) {
            cout << "Invalid seat entry. Try again.\n";
        } else if (seats[r][c] == 'X') {
            cout << "Seat " << row << col << " is already taken. Choose another.\n";
        } else {
            seats[r][c] = 'X';
            cout << "Seat " << row << col << " has been booked.\n";
            valid = true;
        }
    }
}
 
int main() {
    char seats[ROWS][COLS];
    first_seats(seats);
 
    char cont = 'y';
    while (cont == 'y' || cont == 'Y') {
        if (allSeatsTaken(seats)) {
            cout << "All seats are taken!\n";
            break;
        }
        display(seats);
        bookSeat(seats);
 
        cout << "Would you like to book another seat? (y/n): ";
        cin >> cont;
    }
 
    display(seats);
    cout << "Goodbye!\n";
    return 0;
}