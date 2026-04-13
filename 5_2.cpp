//HW 5 Problem 2

#include <iostream>
#include <string>

using namespace std; 

class Pizza{
    private: 
        int type; 
        int size; 
        int toppings;

    public: 
        int deep_dish = 1;
        int hand_tossed = 2; 
        int pan = 3; 
        
        int small = 1; 
        int medium = 2; 
        int large = 3;

        //setters
        void set_type(int type1){
            type = type1;
        }

        void set_size(int size1){
            size = size1;
        }

        void set_toppings(int toppings1){
            toppings = toppings1;
        }

        //getters
        int get_type(){
            return type;
        }

        int get_size(){
            return size;
        }

        int get_toppings(){
            return toppings;
        }

        void get_input();
        double compute_price();
        void output_description();
};

void Pizza::get_input(){
    cout << "Enter pizza type (1 for deep dish, 2 for hand tossed, 3 for pan): ";
    cin >> type;
    while (type < 1 || type > 3) {
        cout << "Invalid input. Please enter 1 for deep dish, 2 for hand tossed, or 3 for pan: ";
        cin >> type;
    }

    cout << "Enter pizza size (1 for small, 2 for medium, 3 for large): ";
    cin >> size;  
    while (size < 1 || size > 3) {
        cout << "Invalid input. Please enter 1 for small, 2 for medium, or 3 for large: ";
        cin >> size;
    }

    cout << "Enter number of toppings: ";
    cin >> toppings;
}

double Pizza::compute_price(){
    double cost; 

    if (size == 1) {
        cost = 10 + 2 * toppings;
    } else if (size == 2) {
        cost = 14 + 2 * toppings;
    } else if (size == 3) {
        cost = 17 + 2 * toppings;
    }

    return cost;
}

void Pizza::output_description(){
    string pizza_type;
    string pizza_size;

    if (type == 1) {
        pizza_type = "deep dish";
    } else if (type == 2) {
        pizza_type = "hand tossed";
    } else if (type == 3) {
        pizza_type = "pan";
    }

    if (size == 1) {
        pizza_size = "small";
    } else if (size == 2) {
        pizza_size = "medium";
    } else if (size == 3) {
        pizza_size = "large";
    }

    cout << "You ordered a " << pizza_size << " " << pizza_type << " pizza with " << toppings << " toppings." << endl;
}

int main() {
    Pizza p; 

    p.get_input();
    double final_cost = p.compute_price();
    p.output_description();

    cout << "Your total comes to: $" << final_cost << endl;

    return 0;
}
