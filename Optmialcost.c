#include <stdio.h>
#include <stdlib.h>

int minCost(int cost[MAX][MAX], int m, int n) {
  int i, j;

  // Create a table to store the optimal cost.
  int dp[m][n];

  // Initialize the table.
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = cost[i][j];
      } else {
        dp[i][j] = cost[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // Return the optimal cost.
  return dp[m - 1][n - 1];
}

int main() {
  int m, n, i, j, cost[MAX][MAX];

  // Get the number of rows and columns.
  printf("Enter the number of rows and columns: ");
  scanf("%d%d", &m, &n);

  // Initialize the cost matrix.
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("Enter the cost at row %d, column %d: ", i + 1, j + 1);
      scanf("%d", &cost[i][j]);
    }
  }

  // Find the optimal cost.
  int optimalCost = minCost(cost, m, n);

  // Print the optimal cost.
  printf("The optimal cost is: %d", optimalCost);

  return 0;
}
