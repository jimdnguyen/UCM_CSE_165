#ifndef StackOfInt_h
#define StackOfInt_h

class StackOfInt
{
    struct stacksOfInt{
        int value;
        stacksOfInt* next;
        void initialize(int array, stacksOfInt* nxt);
    }* head;

    public:
        void initialize();
        void push(int array);
        void peek();
        void* pop();
        void cleanup();
};

#endif