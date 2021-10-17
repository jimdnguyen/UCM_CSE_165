//: C15:Instrument3.cpp
// Late binding with the virtual keyword
#include <iostream>
using namespace std;
enum note { middleC, Csharp, Cflat }; // Etc.
class Instrument {
public:
 virtual void play(note) const {
 cout << "Instrument::play" << endl;
 }
 virtual void prepare(){
     cout<<"Instrument::prepare"<< endl;
 }
};
// Wind objects are Instruments
// because they have the same interface:
class Wind : public Instrument {
public:
 // Override interface function:
 void play(note) const {
 cout << "Wind::play" << endl;
 }
};
void tune(Instrument& i) {
 // ...
 i.play(middleC);
 i.prepare();//called here
}
int main() {
 Wind flute;
 tune(flute); // Upcasting
} ///:~

//Taken from Textbook Thinking in C++ on page 665
//TA looked at code and said it looks good.