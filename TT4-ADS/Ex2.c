#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node
{
    int num;
    struct _node *pNext;
} number;

typedef struct _list
{
    int size;
    number *pHead;
} list;

void init(list *l)
{
    l->size = 0;
    l->pHead = NULL;
}

number* initNumber(int num_input)
{
    number *num = (number *) malloc(sizeof *num);
    num->num = num_input;
    num->pNext = NULL;
    return num;
}

bool isEmpty(list *l)
{
    return (l->size == 0);
}

void insertFirst(number *pNew, list *l)
{
    if (isEmpty(l))
    {
        l->size++;
        l->pHead = pNew;
    }
}

void insert(number *pNew, number *pOld, list *l)
{
    pNew->pNext = pOld->pNext;
    pOld->pNext = pNew;
    l->size++;
}

int sum(number *x)
{
    int temp;
    if (x->pNext == NULL)
    {
        return x->num;
    }
    temp = x->num;
    x = x->pNext;
    return (temp + sum(x));
}

int ex2()
{
    int size = 0, x;
    bool check = false;
    list *l, a;
    l = &a;
    number *n, *y, *p;
    init(l);
    while (check == false)
    {
        printf("Enter the size of the list: ");
        scanf("%d", &size);
        if (size > 0)
        {
            check = true;
        }
        else
        {
            printf("Try again! \n");
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("Number %d is: ", i+1);
        scanf("%d", &x);
        n = initNumber(x);
        if (i == 0)
        {
            insertFirst(n, l);
        }
        else
        {
            insert(n, y, l);
        }
        y = n;
    }
    p = l->pHead;
    printf("Your result is: %d \n", sum(p));
    return 0;
}

int main()
{
    ex2();
    return 0;
}
