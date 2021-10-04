#include <iostream>
#include <string>
#include <fstream>

class Text{
    int id;
    public:
        std::string textObj;
        Text();
        Text(int count);
        //~Text();
        void contents(){
            std::cout<<textObj<<std::endl;
        }
};

Text::Text(){
    textObj = "This is the default case!";
}

Text::Text(int count){
    std::ifstream cppFile("part4.cpp");
    std::string inputWord;
    while(cppFile>>inputWord){
        textObj = textObj + "\n" +  inputWord;
    }
    id = count;
}

int main(){

    
    /*
    Text cpp;
    cpp.contents();
    */
   ///*
    Text cpp2(1);
    cpp2.contents();
    //*/
    return 0;
}