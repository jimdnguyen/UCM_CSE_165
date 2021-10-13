#include <iostream>

using namespace std;


int x,y;
int *px, *py;

/*
int f(){
    //int s = *px + *py; // theres no s = statement here which is why this just stays at 4
    static int s = *px + *py;
    cout << s << endl;
    return s;
}
*/

int f(int a, int b){
    static int s = *px + *py; // 2+2 = 4
    cout << s << endl;
    x = a + s; y = b + s; // 1+4,2+4 = 5,6
    s = x + y;// 5,6 = 11 and b/c this is a static variable, it keeps the value of 11 for the next time this function is called
    //cout << s << endl;//11
    return s;
}

int main(){
    x = y = 2;
    px = &x; py = &y;
    int a = 1, b = 2;
    a = f(a,b); b = f(a,b);

    cout <<*px <<endl << *py << endl;
}