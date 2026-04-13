//HW 5 Problem 3

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Pizza{
    private: 
        int type; 
        int size; 
        int toppings;

    public:
        // Constants for type
        static const int DEEP_DISH = 1;
        static const int HAND_TOSSED = 2;
        static const int PAN = 3;

        // Constants for size
        static const int SMALL = 1;
        static const int MEDIUM = 2;
        static const int LARGE = 3;

    Pizza(){
        type = HAND_TOSSED;
        size = SMALL;
        toppings = 0;
    }

    Pizza(int t, int s, int top){
        /*setType(t);
        setSize(s);
        setToppings(top);*/
        type = t; size = s; toppings = top;
    }

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
        double compute_price() const;
        void output_description() const;
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

double Pizza::compute_price() const{
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

void Pizza::output_description() const{
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

class Order{
    vector <Pizza> Pizzas;

    public: 

    void add_pizza(const Pizza& p){
        Pizzas.push_back(p);
    }

    void add_pizza(int type, int size, int toppings){
        Pizza p(type, size, toppings);
        Pizzas.push_back(p);
    }

    void outputOrder() const {
        double totalPrice = 0.0;
        if (Pizzas.empty()) {
            cout << "No pizzas in the order." << endl;
            return;
        }
        for (size_t i = 0; i < Pizzas.size(); i++) {
            cout << "Pizza #" << i + 1 << ": ";
            Pizzas[i].output_description();
            cout << "Price: $" << Pizzas[i].compute_price() << endl << endl;
            totalPrice += Pizzas[i].compute_price();
        }
        cout << "Total Order Price: $" << totalPrice << endl;
        cout << "--------------------------" << endl;
    }
};


int main()
{
    Order order1;
    int num_pizzas;

    cout << "How many pizzas do you want to order? ";
    cin >> num_pizzas;
    while (num_pizzas < 1) {
        cout << "Invalid input. Please enter a positive number of pizzas: ";
        cin >> num_pizzas;
    }

    for (int i = 1; i <= num_pizzas; i++) {
        cout << "\n---- Pizza " << i << " ----" << endl;
        Pizza p;
        p.get_input();
        order1.add_pizza(p);
    }

    order1.outputOrder();

    return 0;
}