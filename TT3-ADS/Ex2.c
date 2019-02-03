#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _passenger
{
    char name;
    struct _passenger *pNext;
} passenger;

typedef struct _queue
{
    passenger *pFront, *pBack;
    int size;
} queue;

void initQueue(queue *q)
{
    q->size = 0;
    q->pFront = q->pBack = NULL;
}

bool isEmpty(queue *q)
{
    return (q->pFront == NULL);
}

int length(queue *q)
{
    return (q->size);
}

void enqueue(queue *q, char passenger_name)
{
    passenger *a = (passenger*) malloc(sizeof *a);
    a->name = passenger_name;
    a->pNext = NULL;
    if(q->pFront == NULL)
    {
        q->pFront = q->pBack = a;
    }
    else
    {
        a->pNext = q->pBack;
        q->pBack = a;
    }
    q->size++;
}

void dequeue(queue *q)
{
    if(isEmpty(q))
    {
        return;
    }
    else
    {
        if(q->size == 1)
        {
            q->pFront = q->pBack = NULL;
            q->size--;
        }
        else
        {
            passenger *a = q->pBack;
            while(a->pNext != q->pFront)
            {
                a = a->pNext;
            }
            q->pFront = a;
            q->pFront->pNext = NULL;
            q->size--;
        }
    }
}

void display(queue *q)
{
    if (isEmpty(q))
    {
        printf("Empty queue! \n");
        return;
    }
    passenger *a = q->pBack;
    printf("Here is your queue: \n");
    for(int i = 0; i < length(q) - 1; i++)
    {
        printf("%c ", a->name);
        a = a->pNext;
    }
    printf("%c \n", a->name);
}

int main()
{
    char name;
    int size, check_a, check_b = 1, number;
    queue *q, a;
    q = &a;
    initQueue(q);
    printf("How many passengers want to get on the train: \n");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("The passenger name is (1 character only): \n");
        scanf("%s", &name);
        enqueue(q, name);
    }
    printf("------------------------------------------------------------- \n");
    printf("Do you want to add a passenger (1: YES, 0: NO) ? \n");
    scanf("%d", &check_a);
    if (check_a)
    {
        printf("The passenger name is (1 character only): \n");
        scanf("%s", &name);
        enqueue(q, name);
        size++;
    }
    while (check_b)
    {
        printf("How many passenger will be dequeued from the queue: \n");
        scanf("%d", &number);
        if (number > size)
        {
            printf("The number exceeded the size of the train! \n");
        }
        else
        {
            for (int i = 0; i < number; i++)
            {
                passenger *x = q->pFront;
                printf("Passenger %c has left the queue! \n", x ->name);
                dequeue(q);
            }
            check_b = 0;
        }
    }
    printf("------------------------------------------------------------- \n");
    display(q);
    printf("The length of the queue is: %d", length(q));
}

