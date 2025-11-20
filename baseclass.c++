#include <iostream>
using namespace std;

// Vehicle class
class Vehicle
{
public:
    string brand;
    string model;

    // Static member to keep track of the number of Vehicle instances
    static int vehicleCount;
    // Constructor increments the vehicle count
    Vehicle(string b, string m)
    {
        brand = b;
        model = m;
        vehicleCount++;
    }
    // displaye vehicle details
    void displayInfo()
    {
        cout << "Brand:" << brand << ", Model:" << model << endl;
    }
};

// defining static variable outside class -requirement
int Vehicle::vehicleCount = 0;

int main()
{
    Vehicle car1("Mercedes", "A-Class");
    Vehicle car2("Tesla", "Cybertruck");

    car1.displayInfo(); // prints brand and the model of car1
    car2.displayInfo();

    cout << "Total Vehicles: " << Vehicle::vehicleCount << endl;

    return 0;
}
