#ifndef StackOfInt_h
#define StackOfInt_h

class StackOfInt
{
    struct stacksOfInt;
    stacksOfInt* ptr;
    
    public:
        void initialize();
        void push(void* dat);
        void cleanup();
};

#endif