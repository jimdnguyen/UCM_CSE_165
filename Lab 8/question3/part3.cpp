//: C12:IostreamOperatorOverloading.cpp
// Example of non-member overloaded operators
#include <iostream>
#include <sstream> // "String streams"
#include <cstring>
using namespace std;
template <class T, int sz = 5>
class IntArray
{
    //int i[sz];
    T i[sz];

public:
    IntArray() { memset(i, 0, sz * sizeof(*i)); }
    T &operator[](int x)
    {
        return i[x];
    }
    friend ostream &operator<<(ostream &os, const T &ia);
    friend istream &operator>>(istream &is, const T &ia);
    int getsz() { return sz; }
};
ostream &operator<<(ostream &os, IntArray<int> &ia)
{
    int size = ia.getsz();
    for (int j = 0; j < size; j++)
    {
        os << ia[j];
        if (j != size - 1)
            os << ", ";
    }
    os << endl;
    return os;
}
istream &operator>>(istream &is, IntArray<int> &ia)
{
    int size = ia.getsz();
    for (int j = 0; j < size; j++)
        is >> ia[j];
    return is;
}
int main()
{
    stringstream input("47 34 56 92 103");
    IntArray<int> I;
    input >> I;
    I[4] = -1; // Use overloaded operator[]
    cout << I;
} ///:~
  //The base code is taken directly from the textbook Thinking in C++ pages 545-546
  //My modifications came from the textbook Thinking in C++ pages 724 -739
  //TA looked at code and said its good