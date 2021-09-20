#include <iostream>

struct linkedList
{
    public:
        int count;
        linkedList* next;

    void initialize(linkedList* nxt, int newCount)
    {
        count = newCount;
        next = nxt;
    }
/*
    void push(int newCount)
    {
        linkedList* tmp = new linkedList;
        tmp->count = newCount;
        tmp->next = Node;
        Node = tmp;
    }
    */
};

void addingList(linkedList* ptrHead, int length)
{
    for(int i = 0; i < length; i++)
    {
        
        linkedList* tmp = new linkedList;
        tmp->count = i + 1;
        tmp->next = ptrHead;
        ptrHead = tmp;
        
    }
}

int main()
{
    linkedList Node;
    linkedList* ptrHead = &Node;
    Node.count = 0;
    int count;
    //std::cout<<ptrHead<<std::endl;
    //std::cout<<Node.count<<std::endl;

    int lengthOfList = 5;
    addingList(ptrHead, lengthOfList);

    std::cout<<Node.count<<std::endl;
    

    
}