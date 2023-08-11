#include <stdio.h>

int isPerfectNumber(int n) {
  int sum = 0;

  // Find the sum of all the divisors of n.
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      sum += i;
    }
  }

  // If the sum of the divisors is equal to n, then n is a perfect number.
  return sum == n;
}

int main() {
  int n;

  // Get the number from the user.
  printf("Enter a number: ");
  scanf("%d", &n);

  // Check if the number is a perfect number.
  if (isPerfectNumber(n)) {
    printf("%d is a perfect number.", n);
  } else {
    printf("%d is not a perfect number.", n);
  }

  return 0;
}
