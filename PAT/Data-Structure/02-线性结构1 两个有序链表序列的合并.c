#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()
{
    List L = (List)malloc(sizeof(struct Node));
    List head = L;
    L->Next = NULL;
    int count;
    scanf("%d", &count);
    while (count--)
    {
        L->Next = (List)malloc(sizeof(struct Node));
        L = L->Next;
        L->Next = NULL;
        scanf("%d", &(L->Data));
    }
    return head;
}

void Print(List L)
{
    if (!L || !L->Next)
        printf("NULL\n");
    while (L->Next)
    {
        L = L->Next;
        printf("%d%c", L->Data, (L->Next ? ' ' : '\n'));
    }
}

List Merge(List L1, List L2)
{
    List L = (List)malloc(sizeof(struct Node));
    List head = L, oL1 = L1, oL2 = L2;
    L1 = L1->Next;
    L2 = L2->Next;
    oL1->Next = NULL;
    oL2->Next = NULL;
    while (L1 && L2)
    {
        if (L1->Data < L2->Data)
        {
            L->Next = L1;
            L1 = L1->Next;
        }
        else
        {
            L->Next = L2;
            L2 = L2->Next;
        }
        L = L->Next;
    }
    while (L1)
    {
        L->Next = L1;
        L1 = L1->Next;
        L = L->Next;
    }
    while (L2)
    {
        L->Next = L2;
        L2 = L2->Next;
        L = L->Next;
    }
    L->Next = NULL;
    return head;
}
