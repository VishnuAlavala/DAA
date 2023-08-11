#include <stdio.h>

int binomialCoeff(int n, int k) {
  int dp[n + 1][k + 1];

  // Initialize the table.
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= min(i, k); j++) {
      if (j == 0 || j == i) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      }
    }
  }

  // Return the binomial coefficient.
  return dp[n][k];
}

int main() {
  int n, k;

  // Get the values of n and k.
  printf("Enter n and k: ");
  scanf("%d%d", &n, &k);

  // Find the binomial coefficient.
  int binomialCoeff = binomialCoeff(n, k);

  // Print the binomial coefficient.
  printf("Binomial coefficient C(%d, %d) is: %d", n, k, binomialCoeff);

  return 0;
}
