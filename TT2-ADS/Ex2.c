#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct _term
{
    int constant;
    int degree;
    struct _term *pNext;
} term;

typedef struct _polynomial
{
    int size;
    term *pHead;
} poly;

void initPoly(poly *p)
{
    p -> size = 0;
    p -> pHead = NULL;
}

term* initTerm(int term_constant, int term_degree)
{
    term *Term =(term*) malloc(sizeof *Term);
    Term -> constant = term_constant;
    Term -> degree = term_degree;
    Term -> pNext = NULL;
    return Term;
}

bool isEmpty_poly(poly *p)
{
    return (p -> size == 0);
}

bool isEmpty_term(term *t)
{
    return (t -> constant == 0);
}

void insertFirst(term *tNew, poly *p)
{
    if (isEmpty_poly(p))
    {
        p -> size++;
        p -> pHead = tNew;
    }
}

void insert(term *tNew_term, term *tOld_term, poly *p)
{
    tNew_term -> pNext = tOld_term -> pNext;
    tOld_term -> pNext = tNew_term;
    p -> size ++;
}

int length(poly *p)
{
    return p -> size;
}

void removeTerm(poly *p, int term_degree)
{
    term *t = p -> pHead;
    if (t -> degree == term_degree)
    {
        p -> pHead = t -> pNext;
        free(t);
        p -> size--;
        return;
    }
    term *u = t -> pNext;
    for (int i = 0; i < length(p); i++)
	{
		if (t -> degree == term_degree)
		{
			u -> pNext = t -> pNext;
			p -> size--;
			free(t);
			break;
		}
		u = t;
		t = t -> pNext;
	}
}

void addTerm(poly *p, int term_constant, int term_degree)
{
    term *t = p -> pHead;
	for (int i = 0; i < length(p); i++)
	{
		if (t -> degree == term_degree)
		{
			t -> constant += term_constant;
			return;
		}
		if (length(p) != 1)
        {
            t = t -> pNext;
        }
    }
    term *temp = initTerm(term_constant, term_degree);
    insert(temp, t, p);
}

int calculate(poly *p, int x)
{
    int result = 0;
    term *t = p -> pHead;
    for (int i = 0; i < length(p); i++)
    {
        result += ((t -> constant) * pow(x, t -> degree));
        t = t -> pNext;
    }
    return result;
}

void displayfunction(poly *p)
{
    term *t = p -> pHead;
    printf("Your function is: \n");
    for (int i = 0; i < length(p) - 1; i++)
    {
        printf("%dx^%d + ", t -> constant, t -> degree);
        t = t -> pNext;
    }
    printf("%dx^%d \n", t -> constant, t -> degree);
}

int main()
{
    int size, constant, degree, check, x;
    poly *p, a;
    term *t, *q;
    p = &a;
    initPoly(p);
    printf("Enter the polynomial function size: \n");
    scanf("%d", &size);
    if (size <= 0)
    {
        printf("NO POLYNOMIAL FUNCTION FOR YOU! \n");
        return 0;
    }
    for(int i = 0; i < size; i++)
    {
        printf("Enter your constant number %d: \n", i + 1);
        scanf("%d", &constant);
        printf("Enter the degree of this constant: \n");
        scanf("%d", &degree);
        t = initTerm(constant, degree);
        if(i == 0)
        {
            insertFirst(t, p);
        }
        else
        {
            insert(t, q, p);
        }
        q = t;
    }
    printf("Do you want to add new term (1: YES, 0: NO) ? \n");
    scanf("%d", &check);
    if (check)
    {
        printf("Insert your constant: \n");
        scanf("%d", &constant);
        printf("Enter the degree of this constant: \n");
        scanf("%d", &degree);
        addTerm(p, constant, degree);
    }
    printf("Do you want to remove any term (1: YES, 0: NO) ? \n");
    scanf("%d", &check);
    if (check)
    {
        printf("Input the term degree you would like to remove: \n");
        scanf("%d", &degree);
        removeTerm(p, degree);
    }
    printf("Input x to calculate the function: \n");
    scanf("%d", &x);
    printf("Your result is: %d \n", calculate(p, x));
    displayfunction(p);
    return 0;
}

