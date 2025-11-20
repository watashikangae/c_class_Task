// task3.c++ - Variables and Polymorphism (Task 3)
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

string companyName = "AutoTech Motors"; // global variable

class Vehicle {
public:
    string brand, model;
    static int count;
    Vehicle(string b, string m) : brand(b), model(m) { ++count; }
    virtual ~Vehicle() { --count; }
    virtual void displayInfo() const { cout << brand << " " << model << "\n"; }
};

int Vehicle::count = 0;

class Car : public Vehicle { int seats; public: Car(string b,string m,int s):Vehicle(b,m),seats(s){ if(s<0) throw runtime_error("Invalid seats"); } void displayInfo() const override { cout<<"Car: "<<brand<<" "<<model<<" | Seats:"<<seats<<"\n"; } };

class Motorbike : public Vehicle { double ec; public: Motorbike(string b,string m,double e):Vehicle(b,m),ec(e){ if(e<0) throw runtime_error("Invalid engine"); } void displayInfo() const override { cout<<"Motorbike: "<<brand<<" "<<model<<" | Engine:"<<ec<<"cc\n"; } };

int main(){
    cout<<"Company: "<<companyName<<"\n";
    Vehicle* list[4];
    try{
        list[0]=new Car("Toyota","Corolla",5);
        list[1]=new Car("Honda","Civic",4);
        list[2]=new Motorbike("Yamaha","R3",321);
        list[3]=new Motorbike("Suzuki","GSX",600);
    }catch(const exception &e){ cerr<<"Create error: "<<e.what()<<"\n"; return 1; }

    cout<<"Total vehicles (static): "<<Vehicle::count<<"\n";
    for(int i=0;i<4;i++) list[i]->displayInfo();

    for(int i=0;i<4;i++) delete list[i];
    return 0;
}
