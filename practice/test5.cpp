#include <iostream>
using namespace std;
int x, y;
int *px, *py;

int f(int a, int b)
{                             // it wants the reference of b not passing value of b
    static int s = *px + *py; // = 2, ignore this the second runthrough, know s = 0 from previous run
    cout << s << endl;        // prints 2 first, next 0 since s = 0 from previous runthrough
    cout << "b" << b << endl;
    cout << "a" << a << endl;
    x = a + s;
    y = b + s;         // 4,4 / 2, 4
    a = x;             // a = 4 / a = 2
    b = y;             // &b = 4 / &b = 4
    s = x - y;         // 4-4 = 0 / 2 - 4 = -2
    cout << s << endl; //prints out 0 next, prinst out -2 next
    return s;
}
int main()
{
    x = y = 1;
    int a = 2, b = 2;
    px = &x;
    py = &y;
    x = f(a, b);         // first runthrough, from this line, we print out 2,0 first, now x = 0
    b = f(a, b);         // second runthrough, from this line, print out 0, -2, now b = -2
    cout << *px << endl; // value of x = 2
    cout << *py << endl;
}
