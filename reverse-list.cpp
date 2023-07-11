#include <ostream>
#include <iostream>

struct node
{
    int data = 0;
    node* next = nullptr;
};

struct list
{
    node* top = nullptr;

    list() {}

    ~list()
    {
        while(top)
        {
            node* next = top->next;
            delete top;
            top = next;
        }
    }

    void push(int i)
    {
        node* n = new node;
        n->data = i;
        n->next = top;
        top = n;
    }

    void reverse()
    {
        if(!top)
            return;
        node* n = nullptr;
        while(top->next)
        {
            std::swap(n, top->next);
            std::swap(n, top);
        }
        top->next = n;
    }
};

std::ostream& operator<<(std::ostream& os, const list& lst)
{
    node* t = lst.top;
    bool f = false;
    while(t)
    {
        if(!f)
            f = true;
        else
            os << " ";

        os << t->data;

        t = t->next;
    }
    return os;
}

int main(int, char**)
{
    list lst;
    for(int i = 0; i < 10; i++)
        lst.push(i);

    std::cout << lst << std::endl;

    lst.reverse();

    std::cout << lst << std::endl;

    return 0;
}
