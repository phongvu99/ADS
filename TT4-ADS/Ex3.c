#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct _node
{
    int disk_number;
    struct _node *pNext;
} disk;

typedef struct _stack
{
    int size;
    char name;
    disk *pTop;
} stack;

void initStack(stack *st, char name_input)
{
    st->size = 0;
    st->name = name_input;
    st->pTop = NULL;
}

bool isEmpty(stack *st)
{
    return (st->size ==0);
}

int length(stack *st)
{
    return (st->size);
}

void push(int disk_input, stack *st)
{
    disk *a = (disk *) malloc(sizeof (disk));
    if (st->size != 0)
    {
        a->pNext = st->pTop;
    }
    a->disk_number = disk_input;
    st->pTop = a;
    st->size++;
}

void pop(stack *st)
{
    if(isEmpty(st))
    {
        return;
    }
    disk *a = st->pTop;
    st->pTop = st->pTop->pNext;
    free(a);
    st->size--;
}

void display(stack *st)
{
    disk *a = st->pTop;
    printf("Stack %c: ", st->name);
    if (isEmpty(st))
    {
        printf("Empty\n");
        return;
    }
    for (int i = 1; i < length(st); i++)
    {
        printf("Disk %d ", a->disk_number);
        a = a->pNext;
    }
    printf("Disk %d \n", a->disk_number);
}

void move(int n, stack *a, stack *b, stack *c)
{
    if (n == 1)
    {
        push(a->pTop->disk_number, c);
        printf("Move #%d from %c to %c \n", a->pTop->disk_number, a->name, c->name);
        pop(a);
    }
    else
    {
        move(n-1, a, c ,b);
        display(a); display(b); display(c);
        move(1, a, b, c);
        display(a); display(b); display(c);
        move(n-1, b, a, c);
    }
}

int toh()
{
    int n = 0, disk_number;
    bool check = false;
    char name_a = 'A', name_b = 'B', name_c = 'C';
    stack *a, *b, *c, d, e, f;
    a = &d; b = &e; c = &f;
    initStack(a, name_a); initStack(b, name_b), initStack(c, name_c);
    printf("Welcome to Tower of Hanoi! \n");
    while (check == false)
    {
        printf("Enter the number of disk(s): ");
        scanf("%d", &n);
        if (n > 0)
        {
            check = true;
        }
        else
        {
            printf("Try again! \n");
        }
    }
    printf("------------------------------------------\n");
    for (int i = n; i > 0; i--)
    {
        disk_number = i;
        push(disk_number, a);
    }
    display(a); display(b); display(c);
    move(n, a, b, c);
    printf("------------------------------------------\n");
    printf("Total moves: %.0lf \n", pow(2, n) - 1);
    display(a); display(b); display(c);
    return 0;
}

int main()
{
    toh();
    return 0;
}



