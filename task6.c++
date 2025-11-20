/ task6.c++ - Exception Handling (Task 6)
#include <iostream>
#include <stdexcept>
using namespace std;

class Car { public: int seats; Car(int s){ if(s<0) throw runtime_error("Invalid seats"); seats=s; } };
class Motorbike { public: double ec; Motorbike(double e){ if(e<0) throw runtime_error("Invalid engine capacity"); ec=e; } };

int main(){
    try{ Car c(-1); }
    catch(const exception &e){ cout<<"Caught car error: "<<e.what()<<"\n"; }

    try{ Motorbike m(-50); }
    catch(const exception &e){ cout<<"Caught bike error: "<<e.what()<<"\n"; }

    cout<<"Exception tests done."<<"\n";
    return 0;
}
// task6.c++ - Exception Handling (Task 6)
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Car{int seats; public: Car(int s):seats(s){ if(s<0) throw runtime_error("Invalid seats"); } };
class Motorbike{double ec; public: Motorbike(double e):ec(e){ if(e<0) throw runtime_error("Invalid engine capacity"); } };

int main(){
    try{ Car c(-1); }
    catch(const exception &e){ cout<<"Caught car error: "<<e.what()<<"\n"; }
    try{ Motorbike m(-50); }
    catch(const exception &e){ cout<<"Caught bike error: "<<e.what()<<"\n"; }
    return 0;
}