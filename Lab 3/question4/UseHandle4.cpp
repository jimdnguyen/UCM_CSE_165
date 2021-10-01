//: C05:UseHandle.cpp
//{L} Handle
// Use the Handle class
#include "Handle4.h" 
int main() {
 Handle4 u;
 u.read();
 u.change(1);
} ///:~ 

/*
The only thing the client programmer can access is the public
interface, so as long as the implementation is the only thing that
changes, the file above never needs recompilation. Thus, although
this isn’t perfect implementation hiding, it’s a big improvement. 

Code is taken from Thinking in C++ textbook on page 297-298
*/

//modifying the code based on the code given from Thinking in C++ textbook on page 314-315