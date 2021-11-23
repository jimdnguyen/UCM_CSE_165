#include <iostream>
#include <stack>

int main()
{
    std::stack<int> fibStack;
    int tmp = 1;
    int prev = 0;
    int input;
    std::cout << "Please enter in a number for Fib" << std::endl;
    std::cin >> input;

    for (int i = 0; i < input; i++)
    {
        tmp = tmp + prev;
        fibStack.push(tmp);
        std::cout << tmp << std::endl;
        tmp = prev;
        prev = fibStack.top();
    }
    return 0;
}
//ask user to input number
//use loop that looks at last 2 #s and pushes
//TA looked over code/output and said it looks good!