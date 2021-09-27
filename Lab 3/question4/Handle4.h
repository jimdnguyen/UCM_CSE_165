//: C05:Handle.h
// Handle classes
#ifndef HANDLE4_H
#define HANDLE4_H
class Handle4 {
 struct Cheshire; // Class declaration only
 Cheshire* smile;
public:
 Handle4();
 ~Handle4();
 int read();
 void change(int);
};
#endif // HANDLE_H ///:~ 

//This is all the client programmer is able to see. The line
//struct Cheshire; 

// Code is taken from Thinking in C++ textbook on page 296

//modifying the code based on the code given from Thinking in C++ textbook on page 314-315