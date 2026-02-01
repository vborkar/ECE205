#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

float rate = 36.75; // rate per hour, up to 40 hours
int hours_worked;
float overtime = 1.5; // overtime multiplier
float gross_pay; //from hours worked including overtime
float total_pay; //total pay after deductions
int num_dependents;
float deductions_dep;

//** Taxes: 6% Social Security, 15% Federal, 4% State, 1% Local, $20 dues
// 2 or more dependents - $40 deduction

//read num hours worked in a week, number dependents -- provide total pay

int main() {

    cout << "Enter number of hours worked in a week: " << endl;
    cin >> hours_worked;
    cout << endl;

    cout << "Enter number of dependents: " << endl;
    cin >> num_dependents;
    cout << endl;

    //find gross pay
    if (hours_worked <= 40) 
        gross_pay = hours_worked * rate;
    else 
        gross_pay = (40 * rate) + ((hours_worked - 40) * rate * overtime);

    cout << fixed << setprecision(2); 
    cout << "Your gross pay is: $" << gross_pay << endl;

    //tax deductions (PRINT THESE)
    float social = gross_pay * 0.06;
    float federal = gross_pay * 0.15;
    float state = gross_pay * 0.04;
    float local = gross_pay * 0.01;
    float dues = 20.0;

    cout << "Social Security tax: $" << social << endl;
    cout << "Federal tax: $" << federal << endl;
    cout << "State tax: $" << state << endl;
    cout << "Local tax: $" << local << endl;
    cout << "Union dues: $" << dues << endl;

    float deductions_tax = social + federal + state + local + dues;

    //deduction if they have depenendents
    if (num_dependents >= 2) {
        deductions_dep = 40.0;
    } else {
        deductions_dep = 0.0;
    }
    
    cout << "Dependent deduction: $" << deductions_dep << endl;
    //final pay
    float tot_deduct = deductions_tax + deductions_dep;
    total_pay = gross_pay - tot_deduct;

    cout << "Total deductions from pay: $" << tot_deduct << endl;
    cout << "Your total pay after deductions is: $" << total_pay << endl;

    return 0;
}