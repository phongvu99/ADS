#include <stdio.h>
#include <stdlib.h>

void display(int a[])
{
    int i = 0;
    while (a[i] != '\0')
    {
        printf("%d ", a[i]);
        i++;
        if (a[i] == '\0')
        {
            printf("\n");
        }
    }
}

int check(int a[])
{
    int i = 1, temp = 0;
    while (a[i] != '\0')
    {
        if (a[i-1] < a[i])
        {
            temp++;
        }
        i++;
    }
    return temp;
}

int bubblesort_new()
{
    int a[100], n, temp, time = 1;
    printf("Enter the size of your array: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalid number! \n");
        return bubblesort_new();
    }
    for (int m = 0; m < n; m++)
    {
        printf("Enter a number for index %d: ", m);
        scanf("%d", &a[m]);
        if (a[m] == 0)
        {
            printf("0 does not work and will not appear in the array \n");
            return bubblesort_new();
        }
        a[m+1] = '\0';
    }
    printf("Original array: ");
    display(a);
    while (check(a) != n-1)
    {
        printf("While loop %d \n", time); // debugging purpose
        for (int i = 1; i < n-1; i++)
        {
            if (a[i-1] > a[i])
            {
                printf("------------------------------------------------- \n");
                printf("%d > %d so we swap them \n", a[i-1], a[i]);
                temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                display(a); // display to see the changes after swapping 2 numbers
            }
        }
        for(int b = n-1; b > 0; b--)
        {
            if (a[b-1] > a[b])
            {
                printf("------------------------------------------------- \n");
                printf("%d > %d so we swap them \n", a[b-1], a[b]);
                temp = a[b];
                a[b] = a[b-1];
                a[b-1] = temp;
                display(a); // display to see the changes after swapping 2 numbers
            }
        }
        time++;
    }
    printf("Sorted array: ");
    display(a);
    return 0;
}

int main()
{
    printf("Algorithm complexity \n");
    printf("Worst O(n^2)\n");
    printf("Best O(n) \n");
    printf("Average O(n^2) \n");
    printf("Any number but 0 will do, thanks! \n");
    bubblesort_new();
    return 0;
}

