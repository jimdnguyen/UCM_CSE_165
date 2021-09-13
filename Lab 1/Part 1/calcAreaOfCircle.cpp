#include <iostream>
#include <cmath> // allows me to use M_PI as a value of Pi.

int main()
{
    // defining all of my variables for the program
    float radiusInput;
    float areaOutput;
    float pi = 3.1415; // unsure how far pi needs to be accurate

    std::cout << "This program is to calculate the area of a circle." << std::endl;
    std::cout << "Please enter in the radius of the circle you would like to calculate the area of." << std::endl;
    std::cin >> radiusInput;
    std::cout << "We have received your input. Please wait as we are calcuating it."<< std::endl;

    // All the calculations to find the area of the circle are run with these two lines of code
    // it just depends if you wantted the manual pi value or the library M_PI value
    // areaOutput = (radiusInput * radiusInput) * pi;
    areaOutput = (radiusInput * radiusInput) * M_PI;

    std::cout << "The area of the circle with radius " << radiusInput << " is " << areaOutput << std::endl;

}

// I used https://www.geeksforgeeks.org/pi-in-c-with-examples/ to see how to use pi with the includes, otherwise I just manually typed in values of pi.
// I used Numconv.cpp to see how we input and output numbers and text