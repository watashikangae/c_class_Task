// vehicle.c++
// Simple Vehicle base class (implements Task 1 and Task 4 helpers)

#include<iostream>
#include <string>
#include <fstream>

using namespace std;

class Vehicle {
public:
	string brand;
	string model;
	static int count;

	Vehicle(const string &b = "", const string &m = "") : brand(b), model(m) {
		++count;
	}

	virtual ~Vehicle() {
		--count;
	}

	// Task 4: updateModel uses a local temporary variable
	void updateModel(const string &newModel) {
		string temp = newModel; // local variable
		model = temp; // update instance variable
	}

	virtual void displayInfo() const {
		cout << "Brand: " << brand << ", Model: " << model << endl;
	}

	virtual void writeToFile(ofstream &out) const {
		out << brand << " " << model << endl;
	}
};

int Vehicle::count = 0;
