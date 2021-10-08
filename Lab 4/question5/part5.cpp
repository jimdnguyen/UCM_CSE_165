//: C14:Combined.cpp
// Inheritance & composition
class A {
    int i;
    public:
        A(int ii) : i(ii) {}
        ~A() {}
        void f() const {}
};
class B {
    int i;
    public:
        B(int ii) : i(ii) {}
        ~B() {}
        virtual void f() const {} // virtual in base class
};
class C : public B {
    A a;
    public:
        C(int ii) : B(ii), a(ii) {}
        ~C() {} // Calls ~A() and ~B()
        void f() const { // Redefinition
            a.f();
            B::f();
        }
};

int main() {
C c(47);
B* bc = &c; // upcasted
bc->f(); // virtual call
} ///:~ 

// The majority of this code I used from the textbook Thinking in C++ on pages 621-622
//added code based on code given in textbook Thinking in C++ on pages 676-677