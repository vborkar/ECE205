//HW 5 Problem 1 

#include <iostream>
using namespace std;

class BicycleSpeedometer {
    public: 
    //mutator: 
    void set_distance(double distance1) {
        distance = distance1;
    }
    void set_time(double time1) {
        time = time1;
    }

    double get_distance() {
        return distance; 
    }

    double get_time() {
        return time; 
    }

    double average_speed() {
        return distance / (time / 60); //returns miles per HOUR
    }
    void display() {
        cout << "Distance traveled: " << distance << " miles" << endl;
        cout << "Time taken: " << time << " minutes" << endl;
        cout << "Average speed: " << average_speed() << " miles per hour" << endl;
    }

    private: 
    double distance; 
    double time; 
    double avg_speed; 
};

int main(){
    BicycleSpeedometer bike; 

    double d; 
    double t; 

    cout << "Enter total distance traveled in miles: ";
    cin >> d; 

    cout << "Enter total time take in minutes: ";
    cin >> t;
    
    bike.set_distance(d);
    bike.set_time(t);   

    bike.display();
}