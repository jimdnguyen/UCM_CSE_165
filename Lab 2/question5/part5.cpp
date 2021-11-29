#include <iostream>

struct linkedList
{
    int count;
    linkedList *next;
};

void createNewLList(linkedList *head, int count)
{
    linkedList *tmp = new linkedList;
    tmp->count = count;
    tmp->next = NULL;

    linkedList *ptrhead = head;
    while (ptrhead->next != NULL)
    {
        ptrhead = ptrhead->next;
    }
    ptrhead->next = tmp;
}

void printLList(linkedList *head)
{
    linkedList *tmp = head;
    while (tmp != NULL)
    {
        std::cout << "Pointer Value is: " << tmp->next << std::endl;
        std::cout << "Count Value is: " << tmp->count << std::endl;
        tmp = tmp->next;
    }
}

int main()
{
    linkedList *Node = new linkedList;
    //Node->next = NULL;
    int counter = 1;
    Node->count = counter;

    int lengthOfList = 5;

    for (int i = 1; i < lengthOfList; i++)
    {
        /* this code is if in case it meant to be the count to 0, not the pointer.
        if(i == lengthOfList - 1)
        {
            createNewLList(Node, 0);
        }
        */
        counter++;
        createNewLList(Node, counter);
    }
    printLList(Node);
}

//Most of my code I used previously from my code in CSE 30.