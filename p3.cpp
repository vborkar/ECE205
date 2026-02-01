#include <iostream>
#include <iomanip>

using namespace std;

double balance = 1000.00;
double interest_rate = 0.015; // 1.5% monthly
double monthly_payment = 50.00;
    
double interest, principal, payment;
double total_interest = 0.0;
double total_paid = 0.0;
int month = 0;

int main() {
   cout << right << setw(8)  << "Month #" << right << setw(12) << "Interest" << right << setw(12) << "Principal" << right << setw(12) << "Balance" << right << setw(18) << "Total Interest" << right << setw(12) << "Total Paid" << endl;
    cout << fixed << setprecision(2);

    // Loop until the balance is paid off
    while (balance > 0) {
        month++;
        
        interest = balance * interest_rate;
        
        // Logic for the final payment
        if (balance + interest < monthly_payment) {
            payment = balance + interest;
            principal = balance;
            balance = 0;
        } else {
            payment = monthly_payment;
            principal = payment - interest;
            balance = balance - principal;
        }

        total_interest += interest;
        total_paid += payment;

        // Data Row - Symbols ($) are placed manually to keep decimals aligned
        cout << right << setw(4) << month << setw(10) << "$" << interest << setw(6) << "$" << principal << setw(8) << "$" << balance << setw(10) << "$" << total_interest << setw(8) << "$" << total_paid << endl;
    }

    return 0;
}