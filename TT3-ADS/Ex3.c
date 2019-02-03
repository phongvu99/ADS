#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct _number
{
    int num;
    struct _number *pNext;
} number;

typedef struct _stack
{
    int size;
    number *pTop;
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
    return (st->size);
}

void push(int num_input, stack *st)
{
    number *a = (number*) malloc(sizeof (number));
    if (st->size != 0)
    {
        a->pNext = st->pTop;
    }
    a->num = num_input;
    st->pTop = a;
    st->size++;
}

void pop(stack *st)
{
    if (isEmpty(st))
    {
        return;
    }
    number *a = st->pTop;
    st->pTop = st->pTop->pNext;
    free(a);
    st->size--;
}

void display(stack *st)
{
    number *a = st->pTop;
    printf("Here is your stack: ");
    for (int i = 0; i < length(st) - 1; i++)
    {
        printf("%d ", a->num);
        a = a->pNext;
    }
    printf("%d \n", a->num);
}

int random_number()
{
    srand(time(NULL));
    int random = 0 + rand() % 10;
    return random;
}

bool verify(number *n1, number *n2, int n3)
{
    bool check;
    if ((n1->num < n3 && n3 < n2->num) || (n2->num < n3 && n3 < n1->num))
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

void step2(stack *st)
{
    number *a = st->pTop;
    bool check = false;
    while (check != true)
    {
        push(random_number(), st);
        if ((st->pTop->num != a->num) && (abs(st->pTop->num - a->num) > 1))
        {
            check = true;
            return;
        }
        else
        {
            pop(st);
        }
    }
}

int step3()
{
    int n3;
    printf("Make a guess: ");
    scanf("%d", &n3);
    return n3;
}

void play()
{
    number *n1, *n2;
    int n3;
    stack *st, b;
    st = &b;
    initStack(st);
    push(random_number(), st);
    n1 = st->pTop;
    step2(st);
    n2 = st->pTop;
    n3 = step3();
    if (verify(n1, n2, n3))
    {
        printf("YOU WIN! \n");
        display(st);
        return;
    }
    else
    {
        printf("Lives remaining: 1 \n");
        pop(st);
        step2(st);
        n2 = st->pTop;
        n3 = step3();
        if (verify(n1, n2, n3))
        {
            printf("YOU WIN! \n");
            display(st);
            return;
        }
        display(st);
        pop(st);
        pop(st);
        printf("You've ran out of lives \n");
        printf("Better luck next time! \n");
        printf("CLEARING THE STACK FOR A NEW GAME! \n");
        printf("-------------------------------------------------------- \n");
        play();
    }
}

int main()
{
    int user_choice = 1;
    printf("LOADING..............\n");
    printf("Welcome to the game! \n");
    printf("How to play: \n");
    printf("Make a guess to see if the number is between n1 and n2. \n");
    printf("That's all, good luck! \n");
    printf("Game begins! \n");
    printf("Lives remaining: 2 \n");
    while(user_choice)
    {
        play();
        printf("KEEP PLAYING (1:YES, 0:NO) ?\n");
        scanf("%d", &user_choice);
        if(user_choice == 0)
        {
            printf("Thank you for playing!");
        }
    }
    return 0;
}
