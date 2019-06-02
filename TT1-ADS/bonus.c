#include <stdio.h>
#include <stdlib.h>

int checkdigit(int isbn)
{
    int thisarray[10], sum = 0, *p;
    p = &isbn;
    for (int i = 8; i >= 0; i--)
    {
        thisarray[i] = *p % 10;
        thisarray[i] = thisarray[i] * (i + 1);
        sum += thisarray[i];
        *p = *p / 10;
    }
    return sum % 11;
}

int main()
{
    int x;
    double isbn, something;
    printf("Input your incomplete ISBN: \n");
    scanf("%lf", &isbn);
    x = checkdigit(isbn);
    if (x <= 9 && x >= 0)
    {
        printf("Your check digit is: %d \n", x);
        printf("Your ISBN is: %.0lf \n", isbn * 10 + x);
    }
    else
    {
        printf("Your ISBN is incorrect! \n");
    }
    return 0;
}
