#include <iostream>

using namespace std;

typedef int itemType;

class Stack
{
public:
    Stack(int max);
    ~Stack();
    void push(itemType v);
    itemType pop();
    int empty();
private:
    struct node
    {
        itemType key;
        struct node *next;
    };
    struct node *head, *z;
};

Stack::Stack(int max)
{
    head = new node;
    z = new node;
    head->next = z;
    z->next = z;
}

Stack::~Stack()
{
    struct node *t = head;
    while(t != z)
    {
        head = t;
        t = t->next;
        delete head;
    }
}

void Stack::push(itemType v)
{
    struct node *t = new node;
    t->key = v;
    t->next = head->next;
    head->next = t;
}

itemType Stack::pop()
{
    itemType x;
    struct node *t = head->next;
    head->next = t->next;
    x = t->key;
    delete t;
    return x;
}

int Stack::empty()
{
    return head->next == z;
}

main()
{
    Stack acc(50);
    acc.push(1);
    cout << acc.pop() << endl;
}
