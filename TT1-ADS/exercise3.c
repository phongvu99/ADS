#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Point
{
    double x, y;
};

double thisisafunction(struct Point a, struct Point b) //this is a good name for a function
{
    return sqrt((b.x - a.x)*(b.x - a.x)+(b.y - a.y)*(b.y - a.y));
}

int main()
{
    struct Point a, b;
    printf("Input your x and y coordinates of point a: \n");
    scanf("%lf" "%lf", &a.x, &a.y);
    printf("Input your x and y coordinates of point b: \n");
    scanf("%lf" "%lf", &b.x, &b.y);
    printf("-------------------------------------------- \n");
    printf("Your euclidean distance is: %.2lf", thisisafunction(a, b));
    return 0;
}



