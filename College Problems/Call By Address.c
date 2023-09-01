#include <stdio.h>
int compareNumbers(int *a, int *b) {
    if (*a > *b)
        return 1;
    else if (*a < *b)
        return -1;
    else
        return 0;
}
int main() {
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    int result = compareNumbers(&num1, &num2);
    if (result == 1)
        printf("%d is greater than %d\n", num1, num2);
    else if (result == -1)
        printf("%d is less than %d\n", num1, num2);
    else
        printf("%d is equal to %d\n", num1, num2);
    return 0;
}
