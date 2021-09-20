#include <iostream>

char* Fxn(char* argu, int size)
{
    char Argu2[size];
    char* ptrArgu2 = new char; // this is my only dynamic storage
    for(int i = 0; i < size; i++)
    {
        Argu2[i] = argu[i];
    }
    ptrArgu2 = Argu2;

    std::cout<<"Char array: " << Argu2<<std::endl;
    std::cout<<"Pointer: "<< ptrArgu2<<std::endl;

    return ptrArgu2;
    delete[] ptrArgu2;
}

int main()
{
    char Argu[] = {"Hi My Name Is Bob!"};

    char* ptrArgu1 = Argu;

    int size = sizeof(Argu);

    char* f1 = Fxn(ptrArgu1, size);
    char* f2 = Fxn(f1, size);
}