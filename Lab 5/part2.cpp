//: C15:AddingVirtuals.cpp
// Adding virtuals in derivation
#include <iostream>
#include <string>
using namespace std;
class Pet {
 string pname;
public: Pet(const string& petName) : pname(petName) {}
 virtual string name() { return pname; } ;
 virtual string speak() = 0;
};// tried to equal speak to "", but had error
//said badly-formed pure specificier only(only = 0 allowed)

class Dog : public Pet {
 string name; 
public:
 Dog(const string& petName) : Pet(petName) {}
 // New virtual function in the Dog class:
 virtual string sit() {
 return Pet::name() + " sits";
 }
 string speak(){ // Override
 return Pet::name() + " says 'Bark!'";
 }
};

int main() {
 Pet* p = new Dog("newBob");
 cout<< p->speak()<<endl;
 
//! cout << "p[1]->sit() = "
//! << p[1]->sit() << endl; // Illegal
} ///:~ 
// Taken from Textbook Thinking in C++ on page 685-686