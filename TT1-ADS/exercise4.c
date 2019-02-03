#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h.>

struct Point
{
    double x, y;
};

double thisisafunction(struct Point a, struct Point b) //this is a good name for a function
{
    return sqrt((b.x - a.x)*(b.x - a.x)+(b.y - a.y)*(b.y - a.y));
}

int checkpoint(struct Point e, struct Point a, struct Point b)
{
    if ((a.x <= e.x & e.x <= b.x) & (b.y <= e.y & e.y <= a.y || a.y <= e.y & e.y <= b.y) || (b.x <= e.x & e.x <= a.x) & (b.y <= e.y & e.y <= a.y || a.y <= e.y & e.y <= b.y))
    {
        printf("CONGRATULATION! Your point is in the rectangle! \n");
        return 1;
    }
    else
    {
        printf("BETTER LUCK NEXT TIME! Your point is not in the rectangle! \n");
        return 0;
    }

}

int main()
{
    double length, width, area;
    bool check = false;
    struct Point a, b, c, d, e;
    while (check != true)
    {
        printf("Input your x and y coordinates of point a: \n");
        scanf("%lf" "%lf", &a.x, &a.y);
        printf("Input your x and y coordinates of point b: \n");
        scanf("%lf" "%lf", &b.x, &b.y);
        if (a.x == b.x || a.y == b.y)
        {
            printf("Your points won't construct a rectangle \n");
            printf("--------------------------------------------- \n");
        }
        else
        {
            printf("Rectangle successfully constructed! \n");
			printf("--------------------------------------------- \n");
            check = true;
        }
    }
    c.x = a.x, c.y = b.y;
    d.x = b.x, d.y = a.y;
    length = thisisafunction(a, c);
    width = thisisafunction(a, d);
    area = length * width;
    printf("Rectangle area is: %.2lf \n", area);
    printf("Input your x and y coordinates for the point you want to check: \n");
    scanf("%lf" "%lf", &e.x, &e.y);
    printf("Check point function returned: %d \n",checkpoint(e, a, b));
    return 0;
}

