#include<stdio.h>
#include<stdlib.h>

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

void InsertFisrt(PPNODE First, PPNODE Last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->prev = NULL;
    newn->data = no;
    newn->next = NULL;

    if((*First == NULL) && (*Tail == NULL))
    {
        *First = newn;
        *Tail = newn;
    }
    else
    {
        newn->next = *First;
        (*First)->prev = newn;
        *First = newn;
    }
    (*First)->prev = *Last;
    (*Last)->next = *First;
}

void InsertLast(PPNODE First, PPNODE Last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->prev = NULL;
    newn->data = no;
    newn->next = NULL;

    if((*First == NULL) && (*Tail == NULL))
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        (*Last)->next = newn;
        newn->prev = *Last;
        *Last = newn;
    }
    (*First)->prev = *Last;
    (*Last)->next = *First;
}

int main()
{
    PNODE Head = NULL;
    PNODE Tail = NULL;

    return 0;
}