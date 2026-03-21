//Homework 4 Problem 4 

#include <iostream>
using namespace std;

void initBoard(char board[]) {
    for (int i = 0; i < 9; i++)
        board[i] = '1' + i;
}

void displayBoard(char board[]) {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i];
        if ((i + 1) % 3 == 0) cout << "\n";
        else cout << " |";
    }
    cout << "\n";
}

bool checkWin(char board[], char player) {
    // Rows, columns, diagonals
    int wins[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, // rows
        {0,3,6}, {1,4,7}, {2,5,8}, // cols
        {0,4,8}, {2,4,6}           // diagonals
    };
    for (int i = 0; i < 8; i++) {
        if (board[wins[i][0]] == player &&
            board[wins[i][1]] == player &&
            board[wins[i][2]] == player)
            return true;
    }
    return false;
}

bool boardFull(char board[]) {
    for (int i = 0; i < 9; i++)
        if (board[i] != 'X' && board[i] != 'O') return false;
    return true;
}

void getMove(char board[], char player) {
    int pos;
    bool valid = false;
    while (!valid) {
        cout << "Player " << player << ", enter position (1-9): ";
        cin >> pos;
        if (pos < 1 || pos > 9) {
            cout << "Out of range. Try again.\n";
        } else if (board[pos - 1] == 'X' || board[pos - 1] == 'O') {
            cout << "Position already taken. Try again.\n";
        } else {
            board[pos - 1] = player;
            valid = true;
        }
    }
}

int main() {
    char board[9];
    initBoard(board);

    char players[2] = {'X', 'O'};
    int turn = 0;

    cout << "=== Tic-Tac-Toe ===\n";
    displayBoard(board);

    while (true) {
        char current = players[turn % 2];
        getMove(board, current);
        displayBoard(board);

        if (checkWin(board, current)) {
            cout << "Player " << current << " wins!\n";
            break;
        }
        if (boardFull(board)) {
            cout << "It's a draw!\n";
            break;
        }
        turn++;
    }

    return 0;
}