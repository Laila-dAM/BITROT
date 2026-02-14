#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1 = 10;
    int n2 = 20;
    int sum = n1 + n2;

    printf("Sum of %d and %d is %d\n", n1, n2, sum);

    for (int i = 0; i < 5; i++) {
        printf("Loop iteration: %d\n", i);
    }

    int factorial = 1;
    for (int i = 1; i <= 5; i++) {
        factorial *= i;
    }
    printf("Factorial of 5 is %d\n", factorial);

    int result = 0;
    int a = 7;
    int b = 3;
    result = a * b + sum;
    printf("Computed result: %d\n", result);

    return 0;
}
