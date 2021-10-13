#include <iostream>
#include <ctime>
#include <unistd.h>
#include <bits/stdc++.h>

class Clock{

public:
    virtual void virtualVoid(){
        
    };
    void nonVirtualVoid(){
    
    };

};

class inheritClock : public Clock{
//TA said I dont need anything inside here
    

};

int main(){
    inheritClock inClock;
    //for loop 100 times
    //to call virtual function
    //to count time and print out time
    //then 
    //another for loop 100 times
    //to call nonvirtual function
    // to count time and print out time 

    Clock* ptrClock = &inClock;
    clock_t tmpVirtualClock;
    clock_t tmpVirtualClock2;
    tmpVirtualClock = clock();
    for(int i = 0; i < 1000000000; i++){
        ptrClock -> virtualVoid();
    }
    tmpVirtualClock2 = clock();
    double time_taken = double(tmpVirtualClock2-tmpVirtualClock) / double(CLOCKS_PER_SEC);
    std::cout<< "Virtual Took: " << std::fixed << time_taken << std::setprecision(5)<<std::endl;

    // 

    clock_t tmpNonVirtualClock;
    clock_t tmpNonVirtualClock3;
    tmpNonVirtualClock = clock();
    for(int i = 0; i < 1000000000; i++){
        ptrClock -> nonVirtualVoid();
    }
    //sleep(2);
    tmpNonVirtualClock3 = clock();
    double time_taken2 = double(tmpNonVirtualClock3-tmpNonVirtualClock) / double(CLOCKS_PER_SEC);
    std::cout<< "Non-Virtual Took: " << std::fixed << time_taken2 << std::setprecision(5)<<std::endl;
    return 0;
}