#include <iostream>
using namespace std;
/*
class Test{
    public:
        Test(){cout<<"Hello from Test()";}
};

int main(){
    cout <<"Main started";
    return 0;
}
*/

int fun(int x, int y = 0, int z = 0)
{
    return (x + y + z);
}
int main()
{
    cout << fun(10);
}