#include <iostream>
//convert into template once finished

class SList
{
public:
    class Node
    {
    public:
        int data;
        Node *next;
    };
    Node *headNode;
    Node *tailNode;
    SList()
    {
        headNode = new Node;
        tailNode = new Node;
    }
    ~SList() { std::cout << "Destructor SList called" << std::endl; }
    void insert(int data);
    void print();
    void erase(int location); //find data and delete it
};

void SList::insert(int data)
{
    Node *tmp = new Node;
    tmp->data = data;
    tmp->next = NULL;

    Node *ptrhead = headNode;
    while (ptrhead->next != NULL)
    {
        ptrhead = ptrhead->next;
    }
    ptrhead->next = tmp;
}

void SList::print()
{
    Node *tmp = headNode;
    while (tmp != NULL)
    {
        std::cout << "Pointer Value is: " << tmp->next << std::endl;
        std::cout << "Count Value is: " << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

int main()
{
    SList head;
    std::cout << "slist cteated" << std::endl;
    int counter = 1;
    head.headNode->data = counter;
    std::cout << "cpunter cteated" << std::endl;
    int lengthOfList = 5;
    for (int i = 1; i < lengthOfList; i++)
    {
        counter++;
        head.insert(counter);
    }
    head.print();
    std::cout << "priny cteated" << std::endl;
    for (auto itr = head.begin(); itr != head.end(); itr++)
    {
        std::cout << *itr << std::endl;
    }

    return 0;
}

//https://www.geeksforgeeks.org/difference-between-singly-linked-list-and-doubly-linked-list/
//http://www2.lawrence.edu/fast/GREGGJ/CMSC270/linked/iterators.html