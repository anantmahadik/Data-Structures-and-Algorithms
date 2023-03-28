#include<iostream.h>
using namespace std;

struct node 
{
    int data;
    struct node * next;
};

class Stack
{
    public:
        struct node *next;
        int iCount;

        Stack();

        bool IsStackEmpty();
        void Push(int no);
        int Pop();
        void Display();
};

Stack :: Stack()
{

}

bool Stack :: IsStackEmpty()
{

}

int Stack :: Pop()
{

}

void Stack :: Display()
{

}

int main()
{
    Stack obj;

    return 0;
}