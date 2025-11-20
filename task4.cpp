// task4.c++ - Local Variables and Model Update (Task 4)
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    string brand, model;
    Vehicle(string b, string m) : brand(b), model(m) {}
    void updateModel(const string &newModel) { string tmp = newModel; model = tmp; }
    void displayInfo() const { cout << brand << " " << model << "\n"; }
};

int main(){
    Vehicle v("Toyota","Corolla");
    cout<<"Before: "; v.displayInfo();
    v.updateModel("Corolla-2025");
    cout<<"After:  "; v.displayInfo();
    return 0;
}
