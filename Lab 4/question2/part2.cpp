#include <iostream>

int* modPtrArray(int* ptr){ // mine
    int* tmpPtr;
    tmpPtr = (ptr + 1);
    return tmpPtr;

}

void modPtrArrayOg(int** ptr2){//modified my int* modPtrArray based off my code in modPtr2Value
    int* tmpPtr2;
    //std::cout<<*(*(ptr2)+1)<<std::endl;
    *ptr2 = (*(ptr2)+1);

}

void modPtr2Value(int** ptr, int *value){//helped with stackflow
    int *tmpPtr = value;
    *ptr = tmpPtr;
}

int main(){

    int a[4] = {5,10,15,20};
    int* ptra = a;
    int* refa;
    int a2 = 50;
    int b = 25;
    int* ptra2 = &a2;
    int* ptrb;

    std::cout<<"Address of Value: " << ptra<<std::endl;
    std::cout<<"Value: " << *ptra<<std::endl;

    refa = modPtrArray(ptra);

    std::cout<<"Address of Value: " << refa<<std::endl;
    std::cout<<"Value: " << *refa<<std::endl;

    ptra = a;

    std::cout<<"Address of Value: " << ptra<<std::endl;
    std::cout<<"Value: " << *ptra<<std::endl;

    modPtrArrayOg(&ptra);

    std::cout<<"Address of Value: " << ptra<<std::endl;
    std::cout<<"Value: " << *ptra<<std::endl;

    std::cout<<"Address of Value: " << ptra2<<std::endl;
    std::cout<<"Value: " << *ptra2<<std::endl;

    modPtr2Value(&ptra2, &b);

    std::cout<<"Address of Value: " << ptra2<<std::endl;
    std::cout<<"Value: " << *ptra2<<std::endl;

    return 0;
}

//https://stackoverflow.com/questions/4844914/having-a-function-change-the-value-a-pointer-represents-in-c
//i did the array one
//i had some issues with just using numbers and the stackflow helped me out.