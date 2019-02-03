#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node* nodePtr;

typedef struct node{
    int value;
    struct node *pNext;
} number;

typedef struct linkedlist{
    int size;
    number *pHead;
} list;

void initList(list *l)
{
    l->size = 0;
    l->pHead = NULL;
}

number* initNode(int num)
{
    number *Number =(number*) malloc(sizeof *Number);
    Number->value = num;
    Number->pNext = NULL;
    return Number;
}

bool isEmpty_list(list *l)
{
    return (l->size == 0);
}

void insertFirst(number *pNew, list *l)
{
    if (isEmpty_list(l))
    {
        l->size++;
        l->pHead = pNew;
    }
}

void insert(number *pNew, number *pOld, list *l)
{
    pNew->pNext =  pOld->pNext;
    pOld->pNext = pNew;
    l->size++;
}

int length(list *l)
{
    return l->size;
}

void display(nodePtr head)
{
    nodePtr temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->pNext;
    }
    printf("\n");
}

void partition(nodePtr head, nodePtr *front, nodePtr *back)
{
   nodePtr fast, slow;
   if (head == NULL || head->pNext == NULL)
   {
       *front = head;
       *back = NULL;
   }
   else // this part of code will find the middle of the linked list
   {
       slow = head;
       fast = head->pNext;
       while (fast != NULL)
       {
           fast = fast->pNext; // move fast pointer
           if (fast != NULL)
           {
               slow = slow->pNext; // move slow pointer
               fast = fast->pNext; // move fast pointer
           }
       }
   }
   *front = head; // the changes will reflect in &a
   *back = slow->pNext; // the changes will reflect in &b
   slow->pNext = NULL; // this will halves the linked list by making pNext of "a" point to NULL
   display(*front); // display the front &a
   display(*back); // display the back &b
}

nodePtr mergeLists(nodePtr a, nodePtr b)
{
    nodePtr mergedList = NULL;
    if (a == NULL)
    {
//        printf("b is: %d \n", b->value); // DEBUGGING PURPOSE
        return b;
    }
    else if (b == NULL)
    {
//        printf("a is: %d \n", a->value); // DEBUGGING PURPOSE
        return a;
    }
    if (a->value <= b->value)
    {
//        printf("a and b are: %d %d \n", a->value, b->value); // DEBUGGING PURPOSE
        mergedList = a;
        mergedList->pNext = mergeLists(a->pNext, b); // recursively compare the elements in the merged list
    }
    else
    {
//        printf("a and b are: %d %d \n", a->value, b->value); // DEBUGGING PURPOSE
        mergedList = b;
        mergedList->pNext = mergeLists(a, b->pNext); // recursively compare the elements in the merged list
    }
    return mergedList;
}

void mergeSort(nodePtr *source)
{
    nodePtr head = *source;
    nodePtr a, b;
    if (head == NULL || head->pNext == NULL)
    {
        return;
    }
//    printf("step 1 \n"); // DEBUGGING PURPOSE
    partition(head, &a, &b);
//    printf("step 2 \n"); // DEBUGGING PURPOSE
    mergeSort(&a);
//    printf("step 3 \n"); // DEBUGGING PURPOSE
    mergeSort(&b);
//    printf("step 4 \n"); // DEBUGGING PURPOSE
    *source = mergeLists(a, b);
}

int main()
{
    int n, value = 0;
    bool check = false;
    number *x, *y;
    list *l, a;
    l = &a;
    initList(l);
    nodePtr *temp = &l->pHead;
    printf("Algorithm complexity \n");
    printf("Worst O(nlog(n)) \n");
    printf("Best O(nlog(n)) \n");
    printf("Average O(nlog(n) \n");
    while (check != true)
    {
        printf("Enter the size of your list: ");
        scanf("%d", &n);
        if(n <= 0)
        {
            printf("List is empty or invalid number \n");
        }
        else
        {
            check = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter a number for index %d: ", i);
        scanf("%d", &value);
        x = initNode(value);
        if (i == 0)
        {
            insertFirst(x, l);
        }
        else
        {
            insert(x, y, l);
        }
        y = x;
    }
    printf("Your linked list: ");
    display(*temp);
    mergeSort(&l->pHead);
    printf("Your sorted linked list: ");
    display(*temp);
    return 0;
}



