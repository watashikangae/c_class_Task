/ task2.c++ - Derived classes and overriding (Task 2)
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Vehicle {
public:
    string brand, model;
    Vehicle(string b, string m) : brand(b), model(m) {}
    virtual ~Vehicle() {}
    virtual void displayInfo() const { cout << brand << " " << model << "\n"; }
};

class Car : public Vehicle {
    int seats;
public:
    Car(string b, string m, int s) : Vehicle(b, m), seats(s) {
        if (s < 0) throw runtime_error("Invalid number of seats");
    }
    void displayInfo() const override { cout << "Car: " << brand << " " << model << " | Seats: " << seats << endl; }
};

class Motorbike : public Vehicle {
    double engineCapacity;
public:
    Motorbike(string b, string m, double e) : Vehicle(b, m), engineCapacity(e) {
        if (e < 0) throw runtime_error("Invalid engine capacity");
    }
    void displayInfo() const override { cout << "Motorbike: " << brand << " " << model << " | Engine: " << engineCapacity << "cc" << endl; }
};

int main() {
    try {
        Car c("Toyota", "Corolla", 5);
        Motorbike mb("Yamaha", "R15", 150);
        c.displayInfo();
        mb.displayInfo();
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}