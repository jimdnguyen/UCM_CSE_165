#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
    // this I just copied from FloatingAsBinary.cpp
    if(argc != 2) {
        std::cout << "Must provide a number" << std::endl;
        exit(1);
    }
    
    double d = atof(argv[1]);
    unsigned char* cp = reinterpret_cast<unsigned char*>(&d);
    std::cout<<sizeof(cp)<<std::endl;
    //
    int counter = 0;
    unsigned char cp2;

    for(int i = sizeof(double)-1; i >= 0 ; i--) { // This loop came from FloatingAsBinary.cpp However, I changed all the conditions
    //i made i =sizeof(double)-1 since we are looping backwards
    //i>=0 since without it, the output is missing 8 bits(which is how much a char has in bits)
    //and i-- since we dont have two called functions 

        cp2 = *(cp + i); // This is how my code knows which parts of char are we converting to binary 
        //since theres only 8bits in char, we need to move the pointer every 8 bits, which is what the line of code above is doing.

        for(int i = 7; i >= 0; i--)// this for loop is taken from printBinary.cpp
            {
                if(cp2 & (1 << i))
                {
                    std::cout << "1";
                }
                else
                {
                    std::cout << "0";
                }

                //I added the counter code to add the spaces to show which bit is the sign, which bits are the exponent, and which bits are the rest
                if(counter == 0) 
                {
                    std::cout<<" ";
                } else if(counter == 11)
                {
                    std::cout<<" ";
                }

            counter++;
        }
    }

    std::cout<<std::endl;

    return 0;  
}

//https://stackoverflow.com/questions/275994/whats-the-best-way-to-do-a-backwards-loop-in-c-c-c#276053 going backwards in loop
// used to to confirm my answers https://www.binaryconvert.com/result_double.html?decimal=053046054
//https://docs.mql4.com/basis/types/integer/integertypes seeing how many bits there are in char