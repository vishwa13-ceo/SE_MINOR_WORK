#include <stdio.h>
// Function to demonstrate call by value
void modifyValue(int num) {
    num = 20; // This modification does not affect the original variable
    printf("Inside modifyValue function: %d\n", num);
}

int main() {
    int original = 10;
    printf("Original Value: %d\n", original);
    modifyValue(original); // Call by value
    printf("After modifyValue is terminated: %d\n", original); // original remains unchanged
    return 0;
}