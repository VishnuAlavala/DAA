#include <stdio.h>

int sumOfDigits(int n) {
  int sum = 0, digit;

  // While the number is not 0,
  while (n > 0) {
    // Get the last digit of the number.
    digit = n % 10;

    // Add the digit to the sum.
    sum += digit;

    // Remove the last digit from the number.
    n /= 10;
  }

  // Return the sum of digits.
  return sum;
}

int main() {
  int n;

  // Get the number from the user.
  printf("Enter a number: ");
  scanf("%d", &n);

  // Find the sum of digits.
  int sum = sumOfDigits(n);

  // Print the sum of digits.
  printf("The sum of digits is: %d", sum);

  return 0;
}
