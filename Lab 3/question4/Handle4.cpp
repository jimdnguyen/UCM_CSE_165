//: C05:Handle.cpp {O}
// Handle implementation
#include "Handle4.h"
#include "require.h"
// Define Handle's implementation:
struct Handle4::Cheshire {
 int i;
};

Handle4::Handle4(){
    smile = new Cheshire;
    smile->i = 0;
}

Handle4::~Handle4(){
    delete smile;
}
int Handle4::read() {
 return smile->i;
}
void Handle4::change(int x) {
 smile->i = x;
} ///:~ 

// Code is taken from Thinking in C++ textbook on page 296-297
//modifying the code based on the code given from Thinking in C++ textbook on page 314-315
/*
void Handle4::cleanup() {
 delete smile;
}

void Handle4::initialize() {
    smile = new Cheshire;
    smile->i = 0;
}
*/