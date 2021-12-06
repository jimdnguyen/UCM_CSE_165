#include <iostream>

template <typename T>
class SList
{
    class Node
    {
    public:
        T data;
        Node *next;
    };

public:
    Node *headNode;
    Node *tailNode;

    SList()
    {
        headNode = new Node;
        tailNode = new Node;
    }
    ~SList() { std::cout << "Destructor SList called" << std::endl; }
    void insert(T data);
    void print();
    void erase(T position); // find location and delete it
    class iterator
    {
        friend class SList;
        Node *curNode;

    public:
        iterator(Node *tmpNode) : curNode(tmpNode) {}
        iterator() : curNode(nullptr) {}
        iterator operator++(T data)
        {
            if (curNode)
            {
                curNode = curNode->next;
                return *this;
            }
        }
        bool operator!=(const iterator &it)
        {
            return curNode != it.curNode;
        }
        T &operator*() const
        {
            return curNode->data;
        }
    };
    iterator begin() const
    {
        return iterator(headNode);
    }
    iterator end() const
    {
        return iterator(tailNode);
    }
};

template <typename T>
void SList<T>::insert(T data)
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

template <typename T>
void SList<T>::erase(T position)
{
    Node *tmp = new Node;
    Node *ptrhead = headNode;

    for (int i = 1; i <= int(position); i++)
    {
        tmp = ptrhead;
        ptrhead = ptrhead->next;
    }
    tmp->next = ptrhead->next;
}

template <typename T>
void SList<T>::print()
{
    Node *tmp = headNode;
    while (tmp != NULL)
    {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

int main()
{
    SList<int> head;
    head.headNode->data = 0;
    std::cout << "slist cteated" << std::endl;
    std::cout << "cpunter cteated" << std::endl;
    int lengthOfList = 5;
    for (int i = 1; i < lengthOfList; i++)
    {
        head.insert(i);
    }
    head.print();

    head.erase(2);
    std::cout << "priny cteated" << std::endl;
    for (auto itr = head.begin(); itr != head.end(); itr++)
    {
        std::cout << *itr << std::endl;
    }

    return 0;
}

// https://www.geeksforgeeks.org/difference-between-singly-linked-list-and-doubly-linked-list/
// http://www2.lawrence.edu/fast/GREGGJ/CMSC270/linked/iterators.html
// https://www.geeksforgeeks.org/implementing-iterator-pattern-of-a-single-linked-list/
// https://www.codementor.io/@codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
//TA looked over code/output and says its good