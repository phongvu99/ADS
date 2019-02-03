#include <stdio.h>
#include <stdlib.h>

int exercise1()
{
	double x, y, result, *first, *second;
	printf("Please input x and y: \n");
	scanf("%lf" "%lf", &x, &y);
	first = &x;
	second = &y;
	result = *first + *second;
	printf("Your result is: %.2lf \n", result);
	return 0;
}

int main()
{
    exercise1();
    return 0;
}
