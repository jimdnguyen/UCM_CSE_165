#include <iostream>
using namespace std;

class A {
public:
 A() { cout << "A\n"; }
  virtual ~A() { cout << "~A\n"; }
};
class B : public A {
public:
 B() { cout << "B\n"; }
  virtual ~B() { cout << "~B\n"; }
};
class C : public B
{ public:
 C() { cout << "C\n"; }
  virtual ~C() { cout << "~C\n"; }
};
int main() {
A* a = new C;
 if ( true ) { C* c = new C; }
 B b;
//delete a;
return 0;
}
// a b c a b c,  a b, b a 