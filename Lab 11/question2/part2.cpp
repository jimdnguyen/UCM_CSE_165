#include <iostream>
#include <vector>
#include <cmath>

const double PI = atan(1.0) * 4;

int main()
{
    std::vector<double> radianValues;
    std::vector<double> sinValues;
    double tmprad;
    double tmpsin;
    int array[5] = {30, 45, 60, 90, 180};
    for (int i = 0; i < 5; i++)
    {

        tmprad = array[i] * (PI / 180);
        radianValues.push_back(tmprad);
        tmpsin = sin(radianValues[i]);
        std::cout << tmpsin << std::endl;
        //sinValues.push_back(tmpsin);
    }

    for (int i = 0; i < sinValues.size(); i++)
    {
        std::cout << sinValues[i] << std::endl;
    }

    return 0;
}
// https://www.geeksforgeeks.org/program-to-convert-degree-to-radian/
// https://stackoverflow.com/questions/1727881/how-to-use-the-pi-constant-in-c
// TA looked over code and output and says they look good!