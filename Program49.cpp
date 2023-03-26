#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyCL
{
    public:
        PNODE First;
        PNODE Last;

        SinglyCL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        void Count();
};

/*
    Return_Value Class_Name :: Function_Name()
    {

    }
*/

void SinglyCL :: InsertFirst(int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))
    {
        *First = *Last = newn;
        (*Last)->next = *First;
    }
    else
    {
        newn->next = *First;
        *First = newn;
        (*Last)->next = *First;
    }
}

void SinglyCL :: InsertLast(int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))
    {
        *First = *Last = newn;
        (*Last)->next = *First;
    }
    else
    {
        (*Last)->next = newn;
        *Last = newn;
        (*Last)->next = *First;
    }
}

void SinglyCL :: Display()
{
    printf("Elements of Linked List are : \n");

    do
    {
        printf("|%d |->",First->data);
        First = First->next;
    }while(First != Last->next);
    printf("\n");
}

int SinglyCL :: Count()
{
    int iCnt = 0;

    do
    {
        iCnt++;
        First = First->next;
    }while(First != Last->next);
    return iCnt;
}

void SinglyCL :: DeleteFirst()
{
    PNODE temp = *First;

    if((*First == NULL) && (*Last == NULL)) 
    {
        return;
    }
    else if(*First == *Last)    
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else    
    {
        *First = (*First)->next;
        free(temp);
        (*Last) ->next = *First;
    }
}

void SinglyCL :: DeleteLast()
{
    PNODE temp = *First;

    if((*First == NULL) && (*Last == NULL))
    {
        return;
    }
    else if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        while(temp->next != (*Last))
        {
            temp = temp->next;
        }
        free(temp->next);
        *Last = temp;
        (*Last)->next = *First;
    }
}

void SinglyCL :: InsertAtPos(int no, int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count(*First, *Last);
    PNODE newn = NULL;
    PNODE temp = *First;

    if((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(First,Last,no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(First,Last,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void SinglyCL :: DeleteAtPos(int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count(*First,*Last);
    PNODE temp1 = *First;
    PNODE temp2 = NULL;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(First,Last);
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast(First,Last);
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1 -> next;
        
        temp1->next = temp2->next;
        free(temp2);
    }
}

int main()
{
    SinglyCL obj;

    int iRet = 0;

    InsertFirst(51);
    InsertFirst(21);
    InsertFirst(11);

    InsertLast(101);
    InsertLast(111);
    InsertLast(121);

    InsertAtPos(105,5);

    Display();
    iRet = Count();

    printf("Number of elements are : %d\n",iRet);

    DeleteAtPos(5);

    Display();
    iRet = Count();

    printf("Number of elements are : %d\n",iRet);

    DeleteFirst();
    DeleteLast();

    Display();
    iRet = Count();

    printf("Number of elements are : %d\n",iRet);

    return 0;
}