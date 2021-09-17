#include <iostream>
#include <string>
#include <fstream>
#include <vector>



int main()
{
    std::string breakWord = "//quit";
    std::string inputWord;
    std::ifstream pdf("inputWords.cpp");
    std::vector<std::pair<std::string,int>> pairedWords;
    int counter = 0;

    while(pdf >> inputWord && inputWord != breakWord)
    {   
        pairedWords.push_back(std::make_pair(inputWord,counter));
        counter++;
    }

    //quit
    /*
    for(int i = 0; i < pairedWords.size(); i++)
    {
        std::cout << "The first word was " << pairedWords[i].first << " and that number was " << pairedWords[i].second <<  std::endl;
    }
    */

    //the interesting words ill use will be #include, int, inputWord

    for(int j = 0; j < pairedWords.size(); j++)
    {
        switch(pairedWords[j].second)
        {
            case 0: std::cout << "Well, it looks like I need to #include this into my cpp file" << std::endl; 
            break;

            case 2: std::cout << "Well, it looks like I need to #include this into my cpp file" << std::endl;
            break;

            case 4: std::cout << "Well, it looks like I need to #include this into my cpp file" << std::endl;
            break;

            case 6: std::cout << "Well, it looks like I need to #include this into my cpp file" << std::endl;
            break;

            case 8: std::cout << "Time for me to int my way down" << std::endl;
            break;
            
            case 27: std::cout << "Time for me to int my way down" << std::endl;
            break;

            case 33: std::cout << "More inputWords? Okay" << std::endl;
            break;

            case 35: std::cout << "More inputWords? Okay" << std::endl;
            break;
        }
    }
    
}
// I did not understand what it meant by "evaluate it by first using a sequence of if statements to "map" an integral value to the word"
// like how many if statements in total?, Is there a particular way I need to link the number with the words while using the if statements?, Also, does the number need to be unique or does every word need the same number if it was already preassigned?
// I just didn't understand what it was asking me so I decided to figure out how to use pairs.
// I used this website to see how to assign values to the string https://www.cplusplus.com/reference/string/string/assign/
// I used this website to see how to pair two things together https://www.cplusplus.com/reference/utility/pair/pair/
// I used this website to see how to use it in a vector and add the two things to the vector https://stackoverflow.com/questions/7897050/adding-to-a-vector-of-pair
 
