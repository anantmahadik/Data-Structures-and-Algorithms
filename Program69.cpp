#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;      
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyLL
{
    public:
        PNODE First;
        PNODE Last;

        DoublyLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

DoublyLL :: DoublyLL()
{
    First = NULL;
    Last = NULL;
}

void DoublyLL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn; 

        First = newn;
    }
}

void DoublyLL ::  InsertLast(int no)
{
    PNODE newn = new NODE;
    PNODE temp = First;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;      
    }
}

void DoublyLL ::  Display()
{
    PNODE temp = First;

    cout<<"Elements of Linked list are"<<"\n";

    cout<<"NULL<=> ";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data <<"|<=> ";
        temp = temp->next;
    }
    cout<<"NULL "<<"\n";
}

int DoublyLL ::  Count()
{
    PNODE temp = First;

    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}

void DoublyLL :: DeleteFirst()
{
    if(First == NULL)  
    {
        return;
    }
    else if((First)->next == NULL) 
    {
        free(First);
        First = NULL;
    }
    else    
    {
        First = (First) -> next;
        free((First)->prev);               
        (First)->prev = NULL;              
    }
}

void DoublyLL :: DeleteLast()
{
    PNODE temp = First;

    if(First == NULL)  
    {
        return;
    }
    else if((First)->next == NULL) 
    {
        free(First);
        First = NULL;
    }
    else    
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}


void DoublyLL :: InsertAtPos(int no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > (NodeCnt + 1)))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;      

        temp = First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next->prev = newn;   
        temp->next = newn;
        newn->prev = temp;      
    }
}

void DoublyLL :: DeleteAtPos(int ipos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;
    int iCnt = 0, NodeCnt = 0;
    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;  
        temp2->next->prev = temp1;      
        free(temp2);
    }
}

int main()
{
    DoublyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.Display();

    obj.InsertFirst(21);
    obj.Display();

    obj.InsertFirst(11);
    obj.Display();

    obj.InsertLast(101);
    obj.Display();

    obj.InsertLast(111);
    obj.Display();

    obj.InsertLast(121);
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of elelemnts are : "<<iRet<<"\n";

    obj.InsertAtPos(105,5);
    obj.Display();

    obj.DeleteAtPos(5);
    obj.Display();

    obj.DeleteFirst();
    obj.DeleteLast();
    
    obj.Display();

    iRet =obj.Count();
    cout<<"Number of elelemnts are : "<<iRet<<"\n";
    
    return 0;
}