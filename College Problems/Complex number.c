#include <stdio.h>
//we used typedef because so that we dont have to write struct complex every where now by 
//writing just writing complex will work 
typedef struct {
    float real;
    float imag;
} Complex;
Complex addComplex(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}
Complex multiplyComplex(const Complex *a, const Complex *b) {
    Complex result;
    result.real = (a->real * b->real) - (a->imag * b->imag);
    result.imag = (a->real * b->imag) + (a->imag * b->real);
    return result;
}
void displayComplex(Complex c) {
    printf("%.2f + %.2fi\n", c.real, c.imag);
}
int main() {
    int choice;
    Complex num1, num2, result;
    while (1) {
        printf("\n--- Complex Number Operations Menu ---");
        printf("\n1. Add Two Complex Numbers");
        printf("\n2. Multiply Two Complex Numbers");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 3) {
            break;
        }
        printf("\nEnter real and imaginary parts of first complex number: ");
        scanf("%f %f", &num1.real, &num1.imag);
        printf("Enter real and imaginary parts of second complex number: ");
        scanf("%f %f", &num2.real, &num2.imag);
        switch (choice) {
            case 1:
                result = addComplex(num1, num2);
                printf("\nResult of Addition: ");
                displayComplex(result);
                break;
            case 2:
                result = multiplyComplex(&num1, &num2);
                printf("\nResult of Multiplication: ");
                displayComplex(result);
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
