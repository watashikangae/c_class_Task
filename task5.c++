// task5.c++ - File Handling (Task 5)
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Vehicle{public: string brand,model; Vehicle(string b,string m):brand(b),model(m){} virtual ~Vehicle(){} virtual void display()const{ cout<<brand<<" "<<model<<"\n";} virtual void write(ofstream &o)const{ o<<brand<<" "<<model<<"\n";} };

class Car:public Vehicle{int seats; public: Car(string b,string m,int s):Vehicle(b,m),seats(s){} void display()const override{ cout<<"Car: "<<brand<<" "<<model<<" seats="<<seats<<"\n";} void write(ofstream&o)const override{ o<<"Car "<<brand<<" "<<model<<" "<<seats<<"\n";} };

class Motorbike:public Vehicle{double ec; public: Motorbike(string b,string m,double e):Vehicle(b,m),ec(e){} void display()const override{ cout<<"Bike: "<<brand<<" "<<model<<" "<<ec<<"cc\n";} void write(ofstream&o)const override{ o<<"Bike "<<brand<<" "<<model<<" "<<ec<<"\n";} };

int main(){
    Vehicle* v[4];
    v[0]=new Car("Toyota","Corolla",5);
    v[1]=new Car("Honda","Civic",4);
    v[2]=new Motorbike("Yamaha","R15",150);
    v[3]=new Motorbike("Kawasaki","Ninja",650);

    ofstream out("vehicles.txt");
    for(int i=0;i<4;i++) v[i]->write(out);
    out.close();

    cout<<"Data written to vehicles.txt. Now reading:\n";
    ifstream in("vehicles.txt"); string line;
    while(getline(in,line)) cout<<line<<"\n";
    in.close();

    for(int i=0;i<4;i++) delete v[i];
    return 0;
}
// task5.c++ - File Handling (Task 5)
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Vehicle{public: string brand,model; Vehicle(string b,string m):brand(b),model(m){} virtual ~Vehicle(){} virtual void display()const{ cout<<brand<<" "<<model<<"\n";} virtual void write(ofstream &o)const{ o<<brand<<" "<<model<<"\n";} };

class Car:public Vehicle{int seats; public: Car(string b,string m,int s):Vehicle(b,m),seats(s){} void display()const override{ cout<<"Car: "<<brand<<" "<<model<<" seats="<<seats<<"\n";} void write(ofstream&o)const override{ o<<"Car "<<brand<<" "<<model<<" "<<seats<<"\n";} };

class Motorbike:public Vehicle{double ec; public: Motorbike(string b,string m,double e):Vehicle(b,m),ec(e){} void display()const override{ cout<<"Bike: "<<brand<<" "<<model<<" "<<ec<<"cc\n";} void write(ofstream&o)const override{ o<<"Bike "<<brand<<" "<<model<<" "<<ec<<"\n";} };

int main(){ cout<<"Company: AutoTech Motors\n"; Vehicle* v[4]; v[0]=new Car("Toyota","Corolla",5); v[1]=new Car("Honda","Civic",4); v[2]=new Motorbike("Yamaha","R15",150); v[3]=new Motorbike("Kawasaki","Ninja",650);
	ofstream out("vehicles.txt"); for(int i=0;i<4;i++) v[i]->write(out); out.close(); cout<<"Saved to vehicles.txt\n"; ifstream in("vehicles.txt"); string s; while(getline(in,s)) cout<<s<<"\n"; for(int i=0;i<4;i++) delete v[i]; return 0; }
