#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void triangle(int input[], int i, int temp, int n)
{
//    printf("temp is: %d \n", temp);

    if (i == n-1) // Base case for i;
        {
            return;
        }

//    printf("{%d %d %d} \n", input[i], input[i+1], input[temp]);

    if (input[temp] == input[i-1]) // Base case for temp
        {
//            printf("Stop, you violate the law! \n");
            return;
        }

    if (temp == n) // Base case for temp
    {
        i++;
        temp = i+1;
        if (i == n-2)
        {
//            printf("hello \n");
            temp = -1;
        }
    }
    if (temp != -1 && temp - i != 1)
    {
        if (((input[i] + input[i+1]) > input[temp]) && ((input[i] + input[temp]) > input[i+1]) && ((input[i+1] + input[temp]) > input[i]))
        {
            printf("{%d %d %d} is a possible triangle \n", input[i], input[i+1], input[temp]);
        }
    }
//    printf("temp is: %d \n", temp);
    triangle(input, i, temp+1, n);
}

int main()
{
   int input_array[100], start, end, n = 0, i = 0, temp = 0;
   bool check = true;
   printf("Enter n elements of the array: ");
   scanf("%d", &n);
   start = 0;
   end = n-1;
   for (i = 0; i < n; i++) {
       printf("Enter input_array[%d]: ", i);
       scanf("%d", &input_array[i]);
    }
   printf("Your unsorted array: \n");
   for (i = 0; i < n; i++) {
        printf("%d ", input_array[i]);
    }
    printf("\n");
    while (check) // Cocktail shaker in TT5. Neat!
    {
        check = false;
        for (int i = start+1; i <= end; i++)
        {
            if (input_array[i-1] > input_array[i])
            {
                temp = input_array[i-1];
                input_array[i-1] = input_array[i];
                input_array[i] = temp;
                check = true;
            }
        }
        if (check == false)
        {
            break;
        }
        check = false;
        end--;
        for(int b = end; b > start; b--)
        {
            if (input_array[b-1] > input_array[b])
            {
                temp = input_array[b-1];
                input_array[b-1] = input_array[b];
                input_array[b] = temp;
                check = true;
            }
        }
        start++;
    }
    printf("Your sorted array: \n");
   for (int i = 0; i < n; i++) {
        printf("%d ", input_array[i]);
    }
    printf("\n");
    i = 0;
    triangle(input_array, i, i+2, n);
}
