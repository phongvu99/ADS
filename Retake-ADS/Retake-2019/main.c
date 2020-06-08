#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node{
    int value;
    struct _node *pNext;
} node;

typedef struct _list{
    int size;
    node *pHead;
} list;

void initList(list *l)
{
    l -> size = 0;
    l -> pHead = NULL;
}

int length(list *l)
{
    return l -> size;
}

node* initNode(int divisor)
{
    node *Node = (node*) malloc(sizeof *Node);
    Node -> value = divisor;
    Node -> pNext = NULL;
    return Node;
}

bool isEmpty_list(list *l)
{
    return (l -> size == 0);
}

void insertFirst(node *pNew, list *l)
{
    if (isEmpty_list(l))
    {
        l -> size++;
        l -> pHead = pNew;
    }
}

void insert(node *pNew_node, node *pOld_node, list *l)
{
    pNew_node -> pNext = pOld_node -> pNext;
    pOld_node -> pNext = pNew_node;
    l -> size++;
}

void removeNode(list *l, int n_value)
{
    node *p = l -> pHead;
    if (p -> value == n_value)
    {
        l -> pHead = p -> pNext;
        free(p);
        l -> size--;
        return;
    }
    node *q = p -> pNext;
    for (int i = 0; i < length(l); i++)
	{
		if (p -> value == n_value)
		{
			q -> pNext = p -> pNext;
			l -> size--;
			free(p);
			break;
		}
		q = p;
		p = p -> pNext;
	}
}

void divisors(int a, int n)
{
    if (a <= 1)
    {
        return;
    }
    else
    {
        if (a % n == 0)
        {
           printf("%d ", n);
        }
        if (n == a/2) return;
        return divisors(a, n+1);
    }
}

void list_info(list *l)
{
    node *p = l-> pHead;
    for (int i = 0; i < length(l); i++)
    {
        printf("%d ", p -> value);
        p = p -> pNext;
    }
}

void perfect(list *l, int a)
{
    int temp = 0;
    node *p = l -> pHead;
    for (int i = 0; i < length(l); i++)
    {
        temp += p -> value;
        p = p -> pNext;
    }
    if (a == temp && a != 0)
    {
        printf("%d is a perfect number \n", a);
    }
    else printf("%d is not a perfect number \n", a);
}

int maxList(list *l)
{
    int max = 0;
    node *p = l -> pHead;
    if (p -> pNext != NULL)
    {
        node *q = p ->pNext;
        max = q ->value;
        for (int i = 1; i <= length(l); i++)
        {
            if (max < p -> value) max = p -> value;
            q = p;
            p = p -> pNext;
        }
    }
    else max = p -> value;
    return max;
}

int minList(list *l)
{
    int min = 0;
    node *p = l -> pHead;
    if (p -> pNext != NULL)
    {
        node *q = p ->pNext;
        min = q ->value;
        for (int i = 1; i <= length(l); i++)
        {
            if (min > p -> value) min = p -> value;
            q = p;
            p = p -> pNext;
        }
    }
    else min = p -> value;
    return min;
}

void selectionsort(int a[], list *l, int c[], int size)
{
    int min = 0, max = 0;
    int p = 0, q = 0;
    if (size % 2 == 0) // Size is an even number
    {
        for (int i = 0; i < size/2; i++)
        {
            printf("i is: %d \n", i);
            if (length(l) != 0) min = minList(l);
            removeNode(l, min);
            printf("Min value: %d \n", min);
            a[i] = min;
            if (length(l) != 0) max = maxList(l);
            removeNode(l, max);
            printf("Max value: %d \n", max);
            if (i == 0) c[i] = max;
            else
            {
                for (int a = i; a > 0; a--) c[a] = c[a-1]; // Create a space for the sorted part II
                c[0] = max;
            }
        }
    }
    else // Size is an odd number
    {
        for (int i = 0; i < size/2 + 1; i++)
        {
            printf("i is: %d \n", i);
            if (length(l) != 0) min = minList(l);
            removeNode(l, min);
            printf("Min value: %d \n", min);
            a[i] = min;
            if (i != size/2)
            {
                max = maxList(l);
                removeNode(l, max);
                printf("Max value: %d \n", max);
                if (i == 0) c[i] = max;
                else
                {
                    for (int a = i; a > 0; a--) c[a] = c[a-1]; // Create a space for the sorted part II
                    c[0] = max;
                }
            }
            else printf("No maximum if size is an odd number \n");
        }
    }
    printf("Your sorted list: ");
    if (size % 2 == 0) // Print out the sorted list when size is an even number
    {
        while (p != size/2)
        {
            printf("%d ", a[p]);
            p++;
        }
    }
    else // Print out the sorted list when size is an odd number
    {
        while (p != size/2 + 1)
        {
            printf("%d ", a[p]);
            p++;
        }
    }
    while (q != size/2)
    {
        printf("%d ", c[q]);
        q++;
    }
    printf("\n");
}



int main()
{
    printf("Name: Phong Vu \n");
    printf("ID: BI8-139 \n");
    int option = 1;
    while (option == 1)
    {
        printf("Ex1 \n");
        int A[100], C[100];
        int a, size, temp;
        list *n, y, *list_a, list_b;
        n = &y;
        list_a = &list_b;
        node *p, *q, *node_a, *node_b;
        initList(n);
        initList(list_a);
        printf("Please enter a number: ");
        scanf("%d", &a);
        if (a <= 1) printf("Your number is <= 1, try again! \n");
        for (int i = 1; i <= a/2; i++)
        {
            if (a % i == 0)
            {
                p = initNode(i);
                if (i == 1) insertFirst(p, n);
                else insert(p, q, n);
                q = p;
            }
        }
        printf("Your linked list: ");
        list_info(n);
        printf("\n");
        printf("Your divisors: ");
        divisors(a, 1);
        printf("\n");
        printf("Ex2 \n");
        perfect(n, a);
        printf("Ex3 \n");
        printf("Enter your list length: ");
        scanf("%d", &size);
        for (int i = 0; i < size; i++)
        {
            printf("Enter value for index %d: ", i);
            scanf("%d", &temp);
            node_a = initNode(temp);
            if (i == 0) insertFirst(node_a, list_a);
            else insert(node_a, node_b, list_a);
            node_b = node_a;

        }
        printf("Your unsorted list: ");
        list_info(list_a);
        printf("\n");
        selectionsort(A, list_a, C, size);
        printf("1: Continue, Any other numbers: Exit \n");
        scanf("%d", &option);
    }
    return 0;
}
