#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyLL
{
    public:
        // Charactristics
        PNODE First;
        int iCount;

        //Behaviours
        SinglyLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int iPos);

        void Display();
};

SinglyLL :: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

void SinglyLL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }   
    else
    {
        newn->next = First;
        First = newn;
        iCount++;
    }
}

void SinglyLL :: InsertLast(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }
    else
    {
        
    }
}

void SinglyLL :: InsertAtPos(int no, int iPos)
{

}

void SinglyLL :: DeleteFirst()
{

}

void SinglyLL :: DeleteLast()
{

}

void SinglyLL :: DeleteAtPosition(int iPos)
{

}

void SinglyLL :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    PNODE temp = First;

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

int main()
{
    SinglyLL obj1;
    SinglyLL obj2;
    
    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    cout<<"Linked List of first object is : "<<"\n";
    obj1.Display();
    cout<<"Number of nodes in First linkedlist are : "<<obj1.iCount<<"\n";

    obj2.InsertFirst(5001);
    obj2.InsertFirst(510);
    obj2.InsertFirst(210);
    obj2.InsertFirst(110);
    cout<<"Linked List of Second object is : "<<"\n";
    obj2.Display();
    cout<<"Number of nodes in Second linkedlist are : "<<obj2.iCount<<"\n";

    return 0;
}