#include <stdio.h>
#include <stdlib.h>

int exercise2()
{
	double sum = 0, *a;
	double thisarray[100];
	int i, n;
	printf("How many elements are there in your array: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		printf("Input index %d: ", i);
		scanf("%lf", &thisarray[i]);
		printf("Your index %d is: %.2lf \n", i, thisarray[i]);
		a = &thisarray[i];
		sum += *a;
	}
	printf("Your sum is: %.2lf \n", sum);
	return 0;
}

int main()
{
    exercise2();
    return 0;
}
