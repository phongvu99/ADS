#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _car{
	int number;
	char name;
	struct _car *pNext;
} car;

typedef struct _train{
	int size;
	car *pHead;
} train;

void initTrain(train *l)
{
    l -> size = 0;
    l -> pHead = NULL;
}
car* initCar(int car_number, char car_name)
{
    car *Car =(car*) malloc(sizeof *Car);
    Car -> number = car_number;
    Car -> name = car_name;
    Car -> pNext = NULL;
    return Car;
}

bool isEmpty_train(train *l)
{
    return (l -> size == 0);
}

bool isEmpty_car(car *n)
{
    return (n -> number == 0);
}

void insertFirst(car *pNew, train *l)
{
    if (isEmpty_train(l))
    {
        l -> size++;
        l -> pHead = pNew;
    }
}

void insert(car *pNew_car, car *pOld_car, train *l)
{
    pNew_car -> pNext = pOld_car -> pNext;
    pOld_car -> pNext = pNew_car;
    l -> size ++;
}

int length(train *l)
{
    return l -> size;
}

void removeCar(train *l, int car_number, char car_name)
{
    car *p = l -> pHead;
    if (p -> number == car_number && p -> name == car_name)
    {
        l -> pHead = p -> pNext;
        free(p);
        l -> size--;
        return;
    }
    car *q = p -> pNext;
    for (int i = 0; i < length(l); i++)
	{
		if (p -> number == car_number && p -> name == car_name)
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

void addCar(train *l, int car_number, char car_name)
{
    car *p = l -> pHead;
    for (int i = 0; i < length(l) - 1; i++)
	{
		p = p -> pNext;
    }
    car *add_car = initCar(car_number, car_name);
    insert(add_car, p, l);
}

void check_Train(train *l)
{
    int check;
    car *p = l -> pHead;
	for (int i = 0; i <= length(l); i++)
	{
		if (isEmpty_car(p))
		{
		    removeCar(l, p -> number, p -> name);
		    check = 1;
		}
		p = p -> pNext;
	}
	if (check == 1)
    {
        printf("-----------------------------------------------------\n");
        printf("All cars with no passengers has been removed! \n");
    }
    else
    {
        printf("-----------------------------------------------------\n");
        printf("No empty car(s) in the train! \n");
    }
}

void train_info(train *l)
{
    car *p = l -> pHead;
    for (int i = 0; i < length(l); i++)
    {
        printf("Car %c has %d passenger(s) \n", p -> name, p -> number);
        p = p -> pNext;
    }
}

int main()
{
    int size, number = 0, check;
    char name;
    train *l, a;
    l = &a;
    car *p, *q;
    initTrain(l);
    printf("What is the size of this train ? \n");
    scanf("%d", &size);
    if (size <= 0)
    {
        printf("NO TRAIN FOR YOU! \n");
        return 0;
    }
    for(int i = 0; i < size; i++)
    {
        printf("How many passengers are there on car number %d: \n", i + 1);
        scanf("%d", &number);
        printf("What is the name of this car (1 character only): \n");
        scanf("%s", &name);
        p = initCar(number, name);
        if(i == 0)
        {
            insertFirst(p, l);
        }
        else
        {
            insert(p, q ,l);
        }
        q = p;
    }
    printf("Do you want to add new car into the train (1: YES, 0: NO) ? \n");
    scanf("%d", &check);
    if (check)
    {
        printf("How many passengers are there on this car: \n");
        scanf("%d", &number);
        printf("What is the name of this car (1 character only): \n");
        scanf("%s", &name);
        addCar(l, number, name);
    }
    check_Train(l);
    train_info(l);
    printf("The length of the train is: %d \n", length(l));
    return 0;
}













