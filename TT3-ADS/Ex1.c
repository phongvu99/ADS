#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _name
{
    char name_user;
    struct _name *pNext;
} name;

typedef struct _stack
{
    int size;
    name *pTop;
} stack;

void initStack(stack *st)
{
    st->size = 0;
    st->pTop = NULL;
}

bool isEmpty(stack *st)
{
    return (st->size == 0);
}

int length(stack *st)
{
    return (st -> size);
}

void push(char name_input, stack *st)
{
    name *a = (name*) malloc(sizeof (name));
    if (st->size != 0)
    {
        a->pNext = st->pTop;
    }
    a->name_user = name_input;
    st->pTop = a;
    st->size++;
}

void pop(stack *st)
{
    if (isEmpty(st))
    {
        return;
    }
    name *a = st->pTop;
    st->pTop = st->pTop->pNext;
    free(a);
    st->size--;
}

void display(stack *st)
{
    name *a = st->pTop;
    for (int i = 0; i < length(st); i++)
    {
        printf("%c",a->name_user);
        a = a->pNext;
    }
}

int main()
{
    int length = 0, i = 0;
    char name_user[100];
    stack *st, b;
    st = &b;
    initStack(st);
    printf("What is your name: \n");
    gets(name_user);
    while (name_user[i] != '\0') // calculate the length of your name
    {
        i++;
        length++;
    }
    for (int i = 0; i < length; i++)
    {
        push(name_user[i], st);
    }
    printf("Your reversed name is: \n");
    display(st);
    return 0;
}



