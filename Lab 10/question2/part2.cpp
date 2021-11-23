#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#define N 3

class Hangman
{
    bool guessedYet = true;
    char *word = "tmp";

public:
    Hangman()
    {
        std::cout << "Welcome to the Hangman Game!" << std::endl;
        std::cout << "You can only guess the letters wrong " << N << " times!" << std::endl;
    }
    ~Hangman() {}
    void setGuessState() { guessedYet = false; }
    bool getGuessState() { return guessedYet; }
    void setWord(char *guessWord) { word = guessWord; }
    char *getWord() { return word; }
};

int main()
{
    std::ifstream cppFile("words.txt");
    std::string inputWord;
    std::vector<std::string> wordFile;
    while (cppFile >> inputWord)
    {
        wordFile.push_back(inputWord);
    }

    int min = 0;
    int max = wordFile.size() - 1;

    srand(time(NULL));
    int num = rand() % (max - min + 1) + min;
    //std::cout << num << std::endl;
    int size = wordFile[num].size();

    Hangman game;
    char *guessWord = new char[wordFile[num].size() + 1];
    std::strcpy(guessWord, wordFile[num].c_str());
    game.setWord(guessWord);
    char input;
    char *tmpWord = game.getWord();
    //std::cout << tmpWord << std::endl;
    std::string displayWord;
    for (int i = 0; i < size; i++)
    {
        displayWord = displayWord + "_";
    }
    int count = 0;
    int strike = 0;

    while (game.getGuessState())
    {
        std::cout << "What you found so far!" << std::endl;
        std::cout << displayWord << std::endl;
        std::cout << "Enter in a letter!" << std::endl;
        std::cin >> input;
        for (int i = 0; i < strlen(tmpWord); i++)
        {
            if (input == tmpWord[i])
            {
                std::cout << "That Letter Exists!" << std::endl;
                displayWord[i] = input;
            }

            if (input != tmpWord[i])
            {
                count++;
            }
        }
        if (count == strlen(tmpWord))
        {
            std::cout << "That Letter did not Exists!" << std::endl;
            strike++;
            std::cout << "That is Strike: " << strike << std::endl;
        }
        count = 0;
        if (strike == N)
        {
            game.setGuessState();
            std::cout << "You did not find the Word!" << std::endl;
            std::cout << "The word was " << tmpWord << std::endl;
        }
        if (tmpWord == displayWord)
        {
            game.setGuessState();
            std::cout << "You found the Word!" << std::endl;
            std::cout << displayWord << std::endl;
        }
    }

    return 0;
}
//https://stackoverflow.com/questions/12657962/how-do-i-generate-a-random-number-between-two-variables-that-i-have-stored
//https://stackoverflow.com/questions/12862739/convert-string-to-char
//TA looked at code/output and says it looks good!