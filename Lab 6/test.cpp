#include <iostream>
#include <string>
struct S {
  S(int line, const std::string& file) :
    line(line), file(file) {
  }
  std::string file;
  int line;
};

#define SCons() S(__LINE__, __FILE__)

int main () {

  S s1 = SCons();
  S s2 = SCons();
  std::cout << s1.line << "\n";
  std::cout << s2.line << "\n";
}   