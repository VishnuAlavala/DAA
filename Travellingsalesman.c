#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int tsp(int cost[MAX][MAX], int n, int mask, int city) {
  int i, min_cost, min_city;

  // Base case: if all cities are visited,
  if (mask == (1 << n) - 1) {
    return cost[city][0];
  }

  // Initialize the minimum cost.
  min_cost = 99999;

  // Try all the unvisited cities as the next city.
  for (i = 0; i < n; i++) {
    if ((mask & (1 << i)) == 0) {
      // Calculate the cost of visiting city i next.
      int new_cost = cost[city][i] + tsp(cost, n, mask | (1 << i), i);

      // If the cost is less than the minimum cost,
      if (new_cost < min_cost) {
        min_cost = new_cost;
        min_city = i;
      }
    }
  }

  // Return the minimum cost.
  return min_cost;
}

int main() {
  int n, i, j, cost[MAX][MAX];

  // Get the number of cities.
  printf("Enter the number of cities: ");
  scanf("%d", &n);

  // Initialize the cost matrix.
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("Enter the cost between city %d and city %d: ", i + 1, j + 1);
      scanf("%d", &cost[i][j]);
    }
  }

  // Find the minimum cost.
  int min_cost = tsp(cost, n, 1, 0);

  // Print the minimum cost.
  printf("The minimum cost is: %d", min_cost);

  return 0;
}
