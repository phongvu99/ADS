#include <stdio.h>
#include <stdlib.h>

int multiply(int num1, int num2)
{
    if (num1 == 0)
    {
        return 0;
    }
    if (num2 == 0)
    {
        return 0;
    }
    if (num1 < 0 && num2 < 0)
    {
        return (-num1 + multiply(num1, num2 + 1));
    }
    if (num2 < 0)
    {
        return (-num1 + multiply(num1, num2 + 1));
    }
    return (num1 + multiply(num1, num2 - 1));
}

int main()
{
    int num1, num2;
    printf("Enter two numbers: \n");
    scanf("%d %d", &num1, &num2);
    printf("Your result is: %d", multiply(num1, num2));
    return 0;
}
