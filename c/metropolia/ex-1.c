/*
 Do not use an array to hold numbers that user enters this exercise!

Write a program that calculates average of positive numbers that user enters. Program asks user to enter
numbers and calculates the average of entered numbers when user enters 0 as the number. The zero is not
included in the average. If user enters a negative number the program must print a message telling that
only positive numbers are accepted and ignore the negative number.
 */

#include <stdio.h>

int main() {
    float number, sum = 0;
    int count = 0;

    printf("Enter positive numbers (enter 0 to stop): \n");

    while (1) {
        printf("Enter a number: ");
        scanf("%f", &number);

        if (number == 0) {
            break;
        } else if (number < 0) {
            printf("Only positive number are accepted. \n");
        } else {
            sum += number;
            count++;
        }
    }

    if (count > 0) {
        float average = sum / count;
        printf("The average of the entered numbers is: %.2f\n", average);
    } else {
        printf("No positive numbers were entered.\n");
    }

    return 0;
}