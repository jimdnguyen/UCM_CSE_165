//: C05:UseHandle.cpp
//{L} Handle
// Use the Handle class
#include "Handle.h" 
int main() {
 Handle u;
 u.initialize();
 u.read();
 u.change(1);
 u.cleanup();
} ///:~ 

/*
The only thing the client programmer can access is the public
interface, so as long as the implementation is the only thing that
changes, the file above never needs recompilation. Thus, although
this isn’t perfect implementation hiding, it’s a big improvement. 

Code is taken from Thinking in C++ textbook on page 297-298
*/