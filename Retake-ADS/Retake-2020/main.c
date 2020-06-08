#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
 * This function check if a number is a prime number
 */

bool primeNumber(int n, int i) {

//    printf("i is: %d \n", i);

    // Base case
    if (n <= 1) {
        return false;
    }

    if (i == n/2 + 1) {
        return true;
    }

    if (n % i == 0) {
        return false;
    }

    return primeNumber(n, ++i);
}

/*
 * This function returns an array of divisors only
 * if the number of divisors are 6.
 * A sphenic number has exactly 8 divisors.
 * If we rule out itself and 1, we are left with 6 divisors.
 */

int* numDivisors(int n, int i, int count) {

//    printf("Count is: %d \n", count);

    static int divs[6];
    // Base case
    if (i == (n/2 + 1)) {
        if (count == 6) {
//            printf("%d has 6 divisors \n", n);

            return divs;
        } else {
            return NULL;
        }
    }

    if (n % i == 0) {
        divs[count] = i;
        count++;
    }

    numDivisors(n, ++i, count);
}

/*
 * The main function responsible for finding all the
 * sphenic numbers from 30 to n.
 */

int sphenicNumbers(int n, int i) {

    // The pointer holds the reference to the divisors array.
    int* ptrDivisors;

    // Divisors array and prime number count.
    int divs[6], count = 0;

    // Temp array to hold three prime numbers in the divisors array.
    int tempDivs[3];

    // Base case
    if (i == n+1) {
        return 0;
    }

    // First sphenic number starts at 30.
    if (n < 30) {
        return 0;
    }

    ptrDivisors = numDivisors(i, 2, 0);

    if (ptrDivisors != NULL) {
        for (int e = 0; e < 6; e++) {
            if(primeNumber(ptrDivisors[e], 2)) {
                tempDivs[count] = ptrDivisors[e];
                count++;
            }
        }
        if (count == 3) {
            if (tempDivs[0] * tempDivs[1] * tempDivs[2] == i) {
                printf("%d is a sphenic number \n", i);
            }
        }
    }

    // Recursive call.
    sphenicNumbers(n, ++i);
}

int main() {
    int n;

    printf("Sphenic Numbers! \n");
    printf("Enter n: \n");

    scanf("%d", &n);
    
    sphenicNumbers(n,30);

    return 0;
}